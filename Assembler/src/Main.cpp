#include <iostream>
#include <span>

#include "../../Libs/include/Assembler.hpp"



int main(int argc, char *argv[]) {
  using std::cout,  std::span, std::endl;
  if (argc < 2) {
    cout << "one arguments is required: " << endl
         << "a file path to a .asm valid file";
    cout << "output will be in the directory where the program is use" << endl;
    cout << "usage example: .\\Assembler.exe Add.asm";
    return EXIT_FAILURE;
  }
  const auto args = span(argv, argc);

  Assembler::Assembler Assembler(args[1]);
  Assembler.writeBinaryToFile();
  return EXIT_SUCCESS;
}

