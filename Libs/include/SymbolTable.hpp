#pragma once
#include <string>
#include <unordered_map>
#include <memory>


namespace SymbolTable {

  using std::unordered_map, std::string, std::unique_ptr;

  class SymbolTable{
    private:
      unordered_map<string, unique_ptr<const int>> symbolTable;
      unsigned int lineAddressCounter = 0;
      unsigned int variableCounter = 16;

    public:

      SymbolTable();

      unsigned int getAddressCounter();

      void increaseAddressCounter();

      unsigned int getVariableCounter();

      void increaseVariableCounter();

      void addEntry(const string symbol, const int address);

      const bool contains(const string& symbol);

      const int getAddress(const string& symbol);
  };
}