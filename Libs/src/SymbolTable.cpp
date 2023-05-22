#include "../include/Utils-Assembler.hpp"
#include "../include/Specs.hpp"
#include "../include/SymbolTable.hpp"

namespace SymbolTable {

  using std::make_unique;

    SymbolTable::SymbolTable() {
      for (const auto& pair : Specs::symbolTablePredefines) {
        symbolTable.emplace(pair.first, make_unique<const int>(pair.second));
      }
    }

    unsigned int SymbolTable::getAddressCounter() {
      return lineAddressCounter;
    }

    void SymbolTable::increaseAddressCounter() {
      lineAddressCounter ++;
    }

    unsigned int SymbolTable::getVariableCounter() {
      return variableCounter;
    }

    void SymbolTable::increaseVariableCounter() {
      variableCounter++;
    }

    void SymbolTable::addEntry(const string symbol, const int address) {
      symbolTable.emplace(symbol, make_unique<const int>(address));
    }

    const bool SymbolTable::contains(const string& symbol) {
      return Utils::hasMapKey(symbolTable, symbol);
    }

    const int SymbolTable::getAddress(const string& symbol) {
      return *symbolTable[symbol].get();
    }
}