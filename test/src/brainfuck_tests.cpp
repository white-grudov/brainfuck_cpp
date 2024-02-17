#include "gtest/gtest.h"
#include <brainfuck.h>

TEST(BrainfuckTest, HelloWorld)
{
    bf::BrainfuckArgs args{/*input_from_args*/false, /*number_mode*/false};
    bf::Brainfuck brainfuck{args};

    std::string program = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<+"
                          "+.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-"
                          "]<+.";
    std::string output = "Hello, World!";
    
    std::string result = brainfuck.parse(program);
    EXPECT_EQ(result, output);
}

TEST(BrainfuckTest, NumAddition)
{
    int num1 = 52;
    int num2 = 34;
    std::string input = std::to_string(num1) + " " + std::to_string(num2);

    bf::BrainfuckArgs args{/*input_from_args*/true, /*number_mode*/true};
    args.input = input;
    bf::Brainfuck brainfuck{args};

    std::string program = ",>,[<+>-]<.";
    std::string output = std::to_string(num1 + num2);
    EXPECT_EQ(brainfuck.parse(program), output);    
}

TEST(BrainfuckTest, InvalidChar)
{
    bf::BrainfuckArgs args{/*input_from_args*/false, /*number_mode*/false};
    bf::Brainfuck brainfuck{args};

    std::string program = ">+++a.";
    EXPECT_THROW(brainfuck.parse(program), bf::invalid_character_error);    
}

TEST(BrainfuckTest, EmptyInput)
{
    bf::BrainfuckArgs args{/*input_from_args*/true, /*number_mode*/true};
    bf::Brainfuck brainfuck{args};

    std::string program = ",>,[<+>-]<.";
    EXPECT_THROW(brainfuck.parse(program), bf::empty_input_error);    
}

TEST(BrainfuckTest, NumberOutOfRange)
{
    std::string input = "531";

    bf::BrainfuckArgs args{/*input_from_args*/true, /*number_mode*/true};
    args.input = input;
    bf::Brainfuck brainfuck{args};

    std::string program = ",>,[<+>-]<.";
    EXPECT_THROW(brainfuck.parse(program), bf::parse_number_error);    
}

TEST(BrainfuckTest, NotANumber)
{
    std::string input = "abc";

    bf::BrainfuckArgs args{/*input_from_args*/true, /*number_mode*/true};
    args.input = input;
    bf::Brainfuck brainfuck{args};

    std::string program = ",>,[<+>-]<.";
    EXPECT_THROW(brainfuck.parse(program), bf::parse_number_error);    
}