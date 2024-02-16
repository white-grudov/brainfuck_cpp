#include <iostream>
#include <brainfuck.h>

int main(int argc, const char *argv[]) 
{
    using namespace bf;

    Brainfuck brainfuck;
    std::cout << brainfuck.parse(",>++++++[<-------->-],[<+>-]<.") << '\n';

    return 0;
}
