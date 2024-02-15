#include "gtest/gtest.h"
#include <brainfuck.h>

class BrainfuckTest : public ::testing::Test 
{
protected:
    virtual void verify() 
    {
        EXPECT_TRUE(true);
    }
};

TEST_F(BrainfuckTest, InitialTest)
{
    verify();
}
