#include <iostream>
#include <fstream>

#include "../include/Utils-Assembler.hpp"


namespace Utils {

  using std::string, std::smatch, std::ifstream, std::istreambuf_iterator;
  using std::ofstream;
  using std::cout, std::endl;

  string removeCharRegexMatch(smatch matches, int matchIndex) {
    const size_t pos = matches.str(matchIndex).find('=');  //  find position of "=" character
    if (pos != string::npos)                             //  check if character is found
      return matches.str(matchIndex).erase(pos, 1);        //  erase the "=" character
    return matches.str(matchIndex);
  }

  bool deleteFile(const string filePath) {
    if (remove(filePath.c_str()) != 0) {
      cout << "Failed to delete the file in path: " << filePath << endl;
      return false;
    }
    return true;
  }

  const string getFileContent(const string HackFilePath) {
    ifstream hackFile(HackFilePath);

    const string compileHack((istreambuf_iterator<char>(hackFile)),
      std::istreambuf_iterator<char>());
    hackFile.close();

    return compileHack;
  }

  void writeToFile(const string& hackFilePath, const vector<string>& linesToFile) {
    ofstream hackFile(hackFilePath);

    if (!hackFile.is_open()) {
      cout << "Failed to open file path to write: " << hackFilePath << endl;
      exit(-1);
    }

    for (const auto& line : linesToFile) {
      hackFile << line;
    }
    hackFile.close();
  }
}