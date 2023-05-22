#pragma once
#include <string>

#include "Mnemonic.hpp"

namespace Code {
  using std::string;
  class Code {
   private:
    static string dest(const string& dest);
    static string comp(const string& comp);
    static string jump(const string& jump);

   public:
    static string getCode(const string& type, const string& mnemonic);
  };
}