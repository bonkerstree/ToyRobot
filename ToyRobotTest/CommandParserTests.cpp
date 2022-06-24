#include "pch.h"

class CommandParserTests : public ::testing::Test
{
  protected:
    CommandParser* parser;
    void SetUp() override
    {
      std::vector<std::string>commandList = {"MOVE", "PLACE"};
      parser = new CommandParser(commandList);
    }

    void TearDown() override
    {
      delete parser;
    }
};

TEST_F(CommandParserTests, parseCommand_CommandWithArgProvided_CommandAndArgumentsAreNotEmpty)
{
  parser->parseCommand("PLACE 1,2,NORTH");

  EXPECT_FALSE(parser->getCommand().empty());
  EXPECT_EQ(parser->getArguments().size(), 3);
}

TEST_F(CommandParserTests, parseCommand_CommandWithSpacedArgProvided_CommandAndArgumentsAreNotEmpty)
{
  parser->parseCommand("   PLACE 1,     2    ,        NORTH    ");

  EXPECT_FALSE(parser->getCommand().empty());
  EXPECT_EQ(parser->getArguments().size(), 3);
}

TEST_F(CommandParserTests, parseCommand_CommandWithoutArgProvided_CommandIsNotEmptyButArgumentsAreEmpty)
{
  parser->parseCommand("MOVE");

  EXPECT_FALSE(parser->getCommand().empty());
  EXPECT_TRUE(parser->getArguments().empty());
}

TEST_F(CommandParserTests, isCommandValid_ValidCommandProvided_ReturnTrue)
{
  parser->parseCommand("PLACE 1,2,NORTH");

  EXPECT_TRUE(parser->isCommandValid());
}

TEST_F(CommandParserTests, isCommandValid_InvalidCommandProvided_ReturnTrue)
{
  parser->parseCommand("ABC");

  EXPECT_FALSE(parser->isCommandValid());
}