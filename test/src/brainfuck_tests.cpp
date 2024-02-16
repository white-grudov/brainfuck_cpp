#include "gtest/gtest.h"
#include <brainfuck.h>

class BrainfuckTest : public ::testing::Test 
{
private:
    bf::Brainfuck brainfuck;

protected:
    virtual void run(std::string program, std::string output) 
    {
        EXPECT_EQ(brainfuck.parse(program), output);
    }
};

TEST_F(BrainfuckTest, HelloWorld)
{
    std::string program = ">++++++++[<+++++++++>-]<.>++++[<+++++++>-]<+.+++++++..+++.>>++++++[<+++++++>-]<+"
                          "+.------------.>++++++[<+++++++++>-]<+.<.+++.------.--------.>>>++++[<++++++++>-"
                          "]<+.";
    std::string output = "Hello, World!";
    run(program, output);
}

TEST_F(BrainfuckTest, InvalidChar)
{
    std::string program = ">+++a.";
    EXPECT_THROW(run(program, ""), bf::brainfuck_error);    
}