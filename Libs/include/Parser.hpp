#pragma once
#include <fstream>
#include <string>


namespace Parser {

  using std::ifstream;
  using std::string;


  const struct InstTYPE {
    inline static const string A_Instruction = "A_INSTRUCCION";
    inline static const string C_Instruction = "C_INSTRUCCION";
    inline static const string L_Instruction = "L_INSTRUCCION";
  };

  class Parser {
   private:
    ifstream asmFile;
    string currentLine;
    string currentInstruction;

    bool isValidFile(const auto& asmFilePath);

    bool hasMoreLines();

    bool skipComment();

    bool skipEmptyLine() noexcept;

    string remove_spaces_and_comments(const string& str);

    bool isA_Instruction();

    bool isC_Instruction();

    bool isL_Instruction();

    string extractSymbol();

    string extractDest();

    string extractJump();

    string extractComp();

    string getDestOrJump(const string& destOrJump);

   public:

    Parser(const char* asmFilePath);

    string getCurrentLine() const;

    string getCurrentInstruction() const;

    void advance();

    string getInstructionType();

    string getSymbol();

    string getDest();

    string getComp();

    string getJump();

    bool isSymbol();

    void resetAsmFile();

  };
}