#pragma once
#include <vector>
#include "Parser.hpp"

#include "SymbolTable.hpp"

namespace Assembler {

	using std::string, std::vector;
	class Assembler {

		private:
			Parser::Parser Parser;
			SymbolTable::SymbolTable symbolTable = {};
			string hackFilePath;

			string integerToBinary(const int number);

			string decimalToBinary(const string& number);

			const string getBinaryAInstruction();

			const string getBinaryCInstruction();

			const string instructionToBinary(const string& InstructionType);

			void firstPass();

			int resolveSymbol();

			const vector<string> secondPass();

			void getHackFilePath(const string asmFilePath);

		public:

			Assembler(const char* asmFilePath);


			void writeBinaryToFile();
	};

}