#pragma once
#include <gtest/gtest.h>

#include "Utils.hpp"
#include "../../Libs/include/Parser.hpp"

TEST(Parser, InvalidAsmFilePath) {
  EXPECT_DEATH(Parser::Parser Parser("./samples/Adds.asm"), "Asm-file path is not valid");
}

TEST(Parser, advance_Add_asm) {
  Parser::Parser Parser("./samples/Add.asm");
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@2") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=A") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@3") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=D+A") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "M=D") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}

TEST(Parser, advance_Max_asm) {
  Parser::Parser Parser("./samples/Max.asm");
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@R0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=M") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@R1") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=D-M") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@OUTPUT_FIRST") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D;JGT") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@R1") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=M") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@OUTPUT_D") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "0;JMP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "(OUTPUT_FIRST)") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@R0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "D=M") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "(OUTPUT_D)") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@R2") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "M=D") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "(INFINITE_LOOP)") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "@INFINITE_LOOP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getCurrentInstruction(), "0;JMP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}

TEST(Parser, instructionType_Add_asm) {
  Parser::Parser Parser("./samples/Add.asm");

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}

TEST(Parser, instructionType_Max_asm) {
  Parser::Parser Parser("./samples/Max.asm");

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "L_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "L_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "L_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "A_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "C_INSTRUCCION") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}

TEST(Parser, getSymbolDestCompJump_Add_asm) {
  Parser::Parser Parser("./samples/Add.asm");
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "2") << Utils::showDebugParser(Parser); 
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "A") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "3") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "D+A") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);

  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}

TEST(Parser, getSymbolDestCompJump_Max_asm) {
  Parser::Parser Parser("./samples/Max.asm");
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "R0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "R1") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "D-M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "OUTPUT_FIRST") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "null") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "JGT") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "R1") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "OUTPUT_D") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "null") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "0") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "JMP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "OUTPUT_FIRST") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "R0") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "OUTPUT_D") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "R2") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "M") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "D") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "null") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "INFINITE_LOOP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getSymbol(), "INFINITE_LOOP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getDest(), "null") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getComp(), "0") << Utils::showDebugParser(Parser);
  EXPECT_EQ(Parser.getJump(), "JMP") << Utils::showDebugParser(Parser);
  Parser.advance();
  EXPECT_EQ(Parser.getInstructionType(), "EOF") << Utils::showDebugParser(Parser);
}