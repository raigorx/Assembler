#pragma once
#include <string>
#include <regex>

namespace Grammar {
  using std::string, std::regex;

  inline const string comment = "//";

  // numbers from 0 to 32767
  inline const string memLoc = "(?:3276[0-7]|327[0-5]\\d|32[0-6]\\d{2}|3[01]\\d{3}|[12]\\d{4}|[1-9]\\d{0,3}|0)";

  inline const string symbol = "[^0-9]-?[a-zA-Z\\d_.$:]*";

  extern const regex A_Instruc;

  extern const string destComp;

  extern const string dest;

  inline const string jumpComp = "(D|\\d)";

  extern const regex comp;

  inline const string jmp = jumpComp + ";(JGT|JEQ|JGE|JLT|JNE|JLE|JMP)";

  extern const regex C_Instruc;

  extern const regex L_Instruc;

}  //  namespace Grammar