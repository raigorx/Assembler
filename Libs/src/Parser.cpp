#include <iostream>
#include <filesystem>
#include <regex>


#include "../include/Utils-Assembler.hpp"
#include "../include/Lexical-Grammar.hpp"
#include "../include/Mnemonic.hpp"
#include "../include/Parser.hpp"

namespace Parser {

  using std::cout, std::endl;
  using std::filesystem::is_regular_file;

  using std::string, std::cerr, std::regex, std::regex_match, std::regex_search, std::smatch;
  using Utils::removeCharRegexMatch, std::ios;

  bool Parser::isValidFile(const auto& asmFilePath) { return is_regular_file(asmFilePath); }

  bool Parser::hasMoreLines() { return !asmFile.eof(); }

  bool Parser::skipComment() {
    return currentLine.compare(0, Grammar::comment.length(), Grammar::comment) == 0;
  }

  bool Parser::skipEmptyLine() noexcept { return !currentLine.size(); }

  string Parser::remove_spaces_and_comments(const string& str) {
    regex pattern("\\s+|//.*");  //  regular expression pattern to match whitespace and comments
    return regex_replace(str, pattern, "");  //  replace matches with an empty string
  }

  bool Parser::isA_Instruction() { return regex_match(currentInstruction, Grammar::A_Instruc); }

  bool Parser::isC_Instruction() { return regex_match(currentInstruction, Grammar::C_Instruc); }

  bool Parser::isL_Instruction() { return regex_match(currentInstruction, Grammar::L_Instruc); }

  string Parser::extractSymbol() {
    smatch matches;
    const regex symbol = regex("@?\\(?(" + Grammar::symbol + "|" + Grammar::memLoc + "\\)?)");
    regex_search(currentInstruction, matches, symbol);
    return matches[1];
  }

  string Parser::extractDest() {
    smatch matches;
    regex_search(currentInstruction, matches, regex(Grammar::dest));
    return getDestOrJump(matches[1]);
  }

  string Parser::extractJump() {
    smatch matches;
    regex_search(currentInstruction, matches, regex(Grammar::jmp));
    return getDestOrJump(matches[2]);
  }

  string Parser::extractComp() {
    smatch matches;
    regex_search(currentInstruction, matches, regex(Grammar::comp));
    return removeCharRegexMatch(matches, 0);
  }

  string Parser::getDestOrJump(const string& destOrJump) {
    if (destOrJump == "" ) return Mnemonic::null;
    return destOrJump;
  }

  Parser::Parser(const char* asmFilePath): asmFile(asmFilePath)  {
    if (!isValidFile(asmFilePath)) {
      cerr << "Asm-file path is not valid" << endl;
      exit(-1);
    }
  }

  string Parser::getCurrentLine() const { return currentLine; }

  string Parser::getCurrentInstruction() const { return currentInstruction; }

  void Parser::advance() {
    do {
      getline(asmFile, currentLine);
    } while ((skipComment() || skipEmptyLine()) && hasMoreLines());

    if (!hasMoreLines()) {
      currentLine = "";
      currentInstruction = "";
      return;
    }

    if (!currentLine.empty())
      currentInstruction = remove_spaces_and_comments(currentLine);
  }

  string Parser::getInstructionType() {
    if (isA_Instruction()) return InstTYPE::A_Instruction;
    if (isC_Instruction()) return InstTYPE::C_Instruction;
    if (isL_Instruction()) return InstTYPE::L_Instruction;
    if (!hasMoreLines()) return "EOF";

    cout << "InstructionType not recognized" << endl;
    exit(-1);
  }

  string Parser::getSymbol() {
    if (getInstructionType() == InstTYPE::A_Instruction) return extractSymbol();
    if (getInstructionType() == InstTYPE::L_Instruction) return extractSymbol();

    return "";
  }

  string Parser::getDest() {
    if (getInstructionType() == InstTYPE::C_Instruction) return extractDest();
    
    cout << "InstructionType must be a C Instruction" << endl;
    exit(-1);
  }

  string Parser::getComp() {
    if (getInstructionType() == InstTYPE::C_Instruction) return extractComp();
    
    cout << "InstructionType must be a C Instruction" << endl;
    exit(-1);
  }

  string Parser::getJump() {
    if (getInstructionType() == InstTYPE::C_Instruction) return extractJump();
    
    cout << "InstructionType must be a C Instruction" << endl;
    exit(-1);
  }

  bool Parser::isSymbol() {
    const string symbolOrNumber = getSymbol();
    return regex_match(symbolOrNumber, regex(Grammar::symbol));
  }

  void Parser::resetAsmFile() {
    asmFile.clear(); // Clear any error flags
    asmFile.seekg(0, ios::beg);
  }


}  //  namespace Parser