#pragma once
#include "../../Libs/include/Parser.hpp"

namespace Utils {
  using std::string;

  string showDebugParser(const Parser::Parser& parser);

  string showDebugCode(const Parser::Parser& parser, const string& mnemonic);
}