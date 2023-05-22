#include <iostream>
#include <sstream>

#include "../include/Utils.hpp"


namespace Utils {
  using std::string, std::cout, std::remove;
  using std::ifstream, std::istreambuf_iterator;
  using std::endl, std::stringstream;

  string showDebugParser(const Parser::Parser & parser) {
    stringstream output;

    output << "Current Instruction: " << parser.getCurrentInstruction() << endl;
    output << "Current Line: " << parser.getCurrentLine() << endl;

    return output.str();
  }

  string showDebugCode(const Parser::Parser& parser, const string& mnemonic) {
    stringstream output;

    output << "Current Instruction: " << parser.getCurrentInstruction() << endl;
    output << "Mnemonic: " << mnemonic << endl;

    return output.str();
  }
}  //  namespace Utils