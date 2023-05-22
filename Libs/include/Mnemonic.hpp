#pragma once
#include <string>
#include <unordered_map>


namespace Mnemonic {
  using std::string, std::unordered_map;

  inline const string null = "null";

  extern const unordered_map<string, string> dest;

  extern const unordered_map<string, string> jump;

  extern const unordered_map<string, string> comp;
}  //  namespace mnemonic