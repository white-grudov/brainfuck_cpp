#include <iostream>
#include <brainfuck.h>

int main(int argc, char *argv[]) 
{
    using namespace bf;

    try
    {
        BrainfuckArgs args{};
        args.parse(argc, argv);

        Brainfuck brainfuck{args};
        std::cout << brainfuck.parse(",>,[<+>-]<.") << '\n';        
    }
    catch(const bf::brainfuck_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
