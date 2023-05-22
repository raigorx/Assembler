#include <iostream>

#include "../include/Utils-Assembler.hpp"
#include "../include/Code.hpp"

namespace Code {

  using std::cout, std::endl;

  string Code::dest(const string& dest) {
    if (Utils::hasMapKey(Mnemonic::dest, dest))
      return Mnemonic::dest.at(dest);

    cout << dest << " dest no found in Mnemonic map" << endl;
    exit(-1);
  }

  string Code::comp(const string& comp) {
    if (Utils::hasMapKey(Mnemonic::comp, comp))
      return Mnemonic::comp.at(comp);

    cout << comp << " comp no found in Mnemonic map" << endl;
    exit(-1);
  }

  string Code::jump(const string& jump) {
    if (Utils::hasMapKey(Mnemonic::jump, jump))
      return Mnemonic::jump.at(jump);

    cout << jump << " jump no found in Mnemonic map" << endl;
    exit(-1);
  }

  string Code::getCode(const string& type, const string& mnemonic) {

    if (type == "dest") return dest(mnemonic);
    if (type == "comp") return comp(mnemonic);
    if (type == "jump") return jump(mnemonic);

    return "";
  }
}