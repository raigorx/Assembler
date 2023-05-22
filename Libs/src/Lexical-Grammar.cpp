#include "../include/Lexical-Grammar.hpp"

namespace Grammar {
  using std::string, std::regex;

  const regex A_Instruc = regex("^@" + memLoc + "|^@" + symbol);

  const string destComp = string("(") + "(?:-?\\d{1,3}|" + symbol + ")" + "(?:" + "[-+]?" +
                          "(?:\\d{1,3}|" + symbol + ")" + ")*" + ")";

  const string dest = "(?:^([AMD]|AM|MD|AD)=" + destComp + ")";

  const regex comp = regex(jumpComp + "(?=;)|=" + destComp);

  const regex C_Instruc = regex(dest + "|" + jmp);

  const regex L_Instruc = regex("\\(" + symbol + "\\)");

}
