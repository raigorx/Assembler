#pragma once
#include <gtest/gtest.h>

#include "Utils.hpp"
#include "../../Libs/include/Parser.hpp"
#include "../../Libs/include/Code.hpp"

TEST(Code, Add_asm) {
  Parser::Parser Parser("./samples/Add.asm");
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0110000")
     << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0000010")
    << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
    << Utils::showDebugCode(Parser, Parser.getComp());
}

TEST(Code, Max_asm) {
  Parser::Parser Parser("./samples/Max.asm");
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
    << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1010011")
    << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100") 
    << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "001")
      << Utils::showDebugCode(Parser, Parser.getJump());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010") 
    << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
    << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0101010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "111")
      << Utils::showDebugCode(Parser, Parser.getJump());

  Parser.advance();
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0101010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "111")
      << Utils::showDebugCode(Parser, Parser.getJump());
}

TEST(Code, Rect_asm) {
  Parser::Parser Parser("./samples/Rect.asm");
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "110")
      << Utils::showDebugCode(Parser, Parser.getJump());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0110000")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();
  Parser.advance();


  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "100")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0111010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110000")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "010")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0000010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "001")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("dest", Parser.getDest()), "011")
      << Utils::showDebugCode(Parser, Parser.getDest());

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "1110010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0001100")
      << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "001")
      << Utils::showDebugCode(Parser, Parser.getJump());

  Parser.advance();
  Parser.advance();
  Parser.advance();

  EXPECT_EQ(Code::Code::getCode("comp", Parser.getComp()), "0101010")
      << Utils::showDebugCode(Parser, Parser.getComp());

  EXPECT_EQ(Code::Code::getCode("jump", Parser.getJump()), "111")
      << Utils::showDebugCode(Parser, Parser.getJump());
}