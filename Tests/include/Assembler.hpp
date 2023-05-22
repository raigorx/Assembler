#pragma once
#include <gtest/gtest.h>

#include "../../Libs/include/Utils-Assembler.hpp"
#include "../../Libs/include/Assembler.hpp"

TEST(Assembler, translateToBinary_Add_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/Add.asm");

  const char* HackFilePath = "./Add.hack";
  Assembler.writeBinaryToFile();

  const string validHack =
      "0000000000000010\n"
      "1110110000010000\n"
      "0000000000000011\n"
      "1110000010010000\n"
      "0000000000000000\n"
      "1110001100001000\n";

  const string compileHack = Utils::getFileContent(HackFilePath);

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}

TEST(Assembler, translateToBinary_MaxL_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/MaxL.asm");

  const char* HackFilePath = "./MaxL.hack";
  Assembler.writeBinaryToFile();

  const string validHack = 
    "0000000000000000\n"
    "1111110000010000\n"
    "0000000000000001\n"
    "1111010011010000\n"
    "0000000000001010\n"
    "1110001100000001\n"
    "0000000000000001\n"
    "1111110000010000\n"
    "0000000000001100\n"
    "1110101010000111\n"
    "0000000000000000\n"
    "1111110000010000\n"
    "0000000000000010\n"
    "1110001100001000\n"
    "0000000000001110\n"
    "1110101010000111\n";

  const string compileHack = Utils::getFileContent(HackFilePath);

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}

TEST(Assembler, translateToBinary_Max_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/Max.asm");

  const char* HackFilePath = "./Max.hack";
  Assembler.writeBinaryToFile();

  const string validHack =
      "0000000000000000\n"
      "1111110000010000\n"
      "0000000000000001\n"
      "1111010011010000\n"
      "0000000000001010\n"
      "1110001100000001\n"
      "0000000000000001\n"
      "1111110000010000\n"
      "0000000000001100\n"
      "1110101010000111\n"
      "0000000000000000\n"
      "1111110000010000\n"
      "0000000000000010\n"
      "1110001100001000\n"
      "0000000000001110\n"
      "1110101010000111\n";

  const string compileHack = Utils::getFileContent(HackFilePath);

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}

TEST(Assembler, translateToBinary_RectL_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/RectL.asm");

  const char* HackFilePath = "./RectL.hack";
  Assembler.writeBinaryToFile();

  const string validHack =
      "0000000000000000\n"
      "1111110000010000\n"
      "0000000000010111\n"
      "1110001100000110\n"
      "0000000000010000\n"
      "1110001100001000\n"
      "0100000000000000\n"
      "1110110000010000\n"
      "0000000000010001\n"
      "1110001100001000\n"
      "0000000000010001\n"
      "1111110000100000\n"
      "1110111010001000\n"
      "0000000000010001\n"
      "1111110000010000\n"
      "0000000000100000\n"
      "1110000010010000\n"
      "0000000000010001\n"
      "1110001100001000\n"
      "0000000000010000\n"
      "1111110010011000\n"
      "0000000000001010\n"
      "1110001100000001\n"
      "0000000000010111\n"
      "1110101010000111\n";

  const string compileHack = Utils::getFileContent(HackFilePath);

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}


TEST(Assembler, translateToBinary_Rect_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/Rect.asm");

  const char* HackFilePath = "./Rect.hack";
  Assembler.writeBinaryToFile();

  const string validHack =
      "0000000000000000\n"
      "1111110000010000\n"
      "0000000000010111\n"
      "1110001100000110\n"
      "0000000000010000\n"
      "1110001100001000\n"
      "0100000000000000\n"
      "1110110000010000\n"
      "0000000000010001\n"
      "1110001100001000\n"
      "0000000000010001\n"
      "1111110000100000\n"
      "1110111010001000\n"
      "0000000000010001\n"
      "1111110000010000\n"
      "0000000000100000\n"
      "1110000010010000\n"
      "0000000000010001\n"
      "1110001100001000\n"
      "0000000000010000\n"
      "1111110010011000\n"
      "0000000000001010\n"
      "1110001100000001\n"
      "0000000000010111\n"
      "1110101010000111\n";

  const string compileHack = Utils::getFileContent(HackFilePath);

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}


TEST(Assembler, translateToBinary_PongL_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/PongL.asm");

  const char* HackFilePath = "./PongL.hack";
  Assembler.writeBinaryToFile();

  const string compileHack = Utils::getFileContent(HackFilePath);

  const string validHack = Utils::getFileContent("./hackSamples/Pong.hack");

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}

TEST(Assembler, translateToBinary_Pong_Asm) {
  using std::string;
  Assembler::Assembler Assembler("./samples/Pong.asm");

  const char* HackFilePath = "./Pong.hack";
  Assembler.writeBinaryToFile();

  const string compileHack = Utils::getFileContent(HackFilePath);

  const string validHack = Utils::getFileContent("./hackSamples/Pong.hack");

  EXPECT_EQ(compileHack, validHack);

  EXPECT_TRUE(Utils::deleteFile(HackFilePath));
}