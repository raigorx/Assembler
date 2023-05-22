#include <bitset>
#include <functional>
#include <filesystem>
#include <iostream>
#include <cassert>

#include "../include/Specs.hpp"
#include "../include/Assembler.hpp"
#include "../include/Code.hpp"
#include "../include/Utils-Assembler.hpp"


namespace Assembler {
	using std::string, std::bitset, std::stoi, std::ofstream, std::endl;
	using std::bind, std::cout, std::from_chars, std::errc;

	Assembler::Assembler(const char* asmFilePath) : Parser(asmFilePath) {
		getHackFilePath(asmFilePath);
	};

	string Assembler::integerToBinary(const int number) {
		bitset<16> binary(number);
		return binary.to_string();
	}

	string Assembler::decimalToBinary(const string& number) {
		int num = {};

		const char* numberBeginPtr = number.data();
		const char* numberEndPtr = number.data() + number.size();

		auto result = from_chars(numberBeginPtr, numberEndPtr, num);

		if (!(result.ec == errc{} && result.ptr == numberEndPtr)) {
			cout << "Error cannot convert string to int " << num << endl;
			exit(-1);
		}

		return integerToBinary(num);
	}


	const string Assembler::getBinaryAInstruction() {
		const string binary = decimalToBinary(Parser.getSymbol());

		ASSERT_BINARY_LENGTH(binary)

		return binary;
	}

	const string Assembler::getBinaryCInstruction() {
		const string comp = Code::Code::getCode("comp", Parser.getComp());
		const string dest = Code::Code::getCode("dest", Parser.getDest());
		const string jump = Code::Code::getCode("jump", Parser.getJump());

		const string binary = Specs::c_instruction_prefix + comp + dest + jump;

		ASSERT_BINARY_LENGTH(binary)

		return binary;
	}

	const string Assembler::instructionToBinary(const string& InstructionType) {

		assert( (InstructionType == Parser::InstTYPE::A_Instruction) || 
			      (InstructionType == Parser::InstTYPE::C_Instruction) && 
			      "Invalid InstructionType");

		typedef std::function<const string()> getBinaryInstruction;
		getBinaryInstruction getBinaryInstructionPtr = nullptr;

		if (InstructionType == Parser::InstTYPE::A_Instruction)
			getBinaryInstructionPtr = bind(&Assembler::getBinaryAInstruction, this);

		if (InstructionType == Parser::InstTYPE::C_Instruction)
			getBinaryInstructionPtr = bind(&Assembler::getBinaryCInstruction, this);

		const string binary = getBinaryInstructionPtr();

		return binary;
	}

	void Assembler::firstPass() {
		Parser.advance();
		while (!Parser.getCurrentLine().empty())
		{
			
			const string instructionType = Parser.getInstructionType();
			
			if (instructionType != Parser::InstTYPE::L_Instruction) {
				symbolTable.increaseAddressCounter();
			}

			if (instructionType == Parser::InstTYPE::L_Instruction) {
				const unsigned int labelAddress = symbolTable.getAddressCounter();
				const string label = Parser.getSymbol();
				symbolTable.addEntry(label, labelAddress);
			}
			
			Parser.advance();
		}
	}

	const int Assembler::resolveSymbol() {
		const string symbol = Parser.getSymbol();
		if (!symbolTable.contains(symbol)) {
			symbolTable.addEntry(symbol, symbolTable.getVariableCounter());
			symbolTable.increaseVariableCounter();
		}

		return symbolTable.getAddress(symbol);
	}

	const vector<string> Assembler::secondPass() {

		vector<string> linesToFile = {};

		Parser.advance();
		while (!Parser.getCurrentLine().empty())
		{
			const string instructionType = Parser.getInstructionType();

			const bool isSymbol = Parser.isSymbol();

			string lineToFile = {};

			if ((instructionType == Parser::InstTYPE::A_Instruction) && isSymbol) {
				const int address = resolveSymbol();
				lineToFile = integerToBinary(address)  + "\n";
			}

			if (!isSymbol) lineToFile = instructionToBinary(instructionType) + "\n";

			linesToFile.push_back(lineToFile);

			Parser.advance();
		}

		return linesToFile;
	}

	void Assembler::getHackFilePath(const string asmFilePath) {

		std::filesystem::path asmPath(asmFilePath);
		string asmFileName = asmPath.filename().string();


		size_t dotIndex = asmFileName.find_last_of(".");

		if (dotIndex == std::string::npos) {
			cout << "No existing extension found" << endl;
			exit(-1);
		}

		hackFilePath = "./" + asmFileName.substr(0, dotIndex + 1) + Specs::hackExtension;
	}

	void Assembler::writeBinaryToFile() {

		firstPass();
		Parser.resetAsmFile();
		const vector linesToFile = secondPass();

		Utils::writeToFile(hackFilePath, linesToFile);
	}
}