#pragma once
#include <regex>
#include <string>
#include <cassert>
#include <vector>

#include "Specs.hpp"

#ifndef NDEBUG
#define ASSERT_BINARY_LENGTH(str) \
    assert(str.length() == Specs::instruction_length \
     && "Instruction binary length should be " + Specs::instruction_length);
#else
#define ASSERT_BINARY_LENGTH(str)
#endif // NDEBUG

namespace Utils {
  using std::string, std::smatch, std::vector;
  
  string removeCharRegexMatch(smatch matches, int matchIndex);

  bool deleteFile(const string filePath);

  const string getFileContent(const string HackFilePath);

  void writeToFile(const string& hackFilePath, const vector<string>& linesToFile);

  template<typename M, typename K>
  bool hasMapKey(const M& map, K key) {
    auto it = map.find(key);
    if (it != map.end()) return true;

    return false;
  }
}  //  namespace Utils