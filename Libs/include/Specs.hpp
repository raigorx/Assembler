#pragma once
#include <string>
#include <map>


namespace Specs {
  using std::string, std::map;

  inline const string c_instruction_prefix = "111";
  inline const unsigned int instruction_length = 16;
  inline const string hackExtension = "hack";

  extern const map<const string, const int> symbolTablePredefines;
  
}  //  namespace Specs