#include "brainfuck_args.h"

#include <iostream>

namespace bf
{

void BrainfuckArgs::help() const noexcept
{
    std::cout << "Options:" << '\n';
    std::cout << "  -h, --help          Show this help message and exit." << '\n';
    std::cout << "  -n, --num-mode      Treat input as numeric values instead of ASCII characters." << '\n';
    std::cout << "  -c  --cmd-input     Use command line arguments as an input instead of the user one." << '\n';
    std::cout << "                      For normal mode, the input should be continuous, e.g. \'123abc\'," << '\n';
    std::cout << "                      but for num-mode numbers should be separated by comma: \'1 2 3 10 32\'." << '\n';
    std::cout << "                      Only numbers in range 0-255 should be used as input for num-mode" << '\n';
    std::cout << "Examples:" << '\n';
    std::cout << "  ./brainfuck run -h" << '\n';
    std::cout << "  ./brainfuck run -n -c 12 3 65" << '\n';
    std::cout << "  ./brainfuck run -c abc123" << '\n';
}

void BrainfuckArgs::parse(int argc, char** argv)
{
    int i = 1;
    for (; i < argc; ++i) 
    {
        std::string arg = argv[i];
        if (arg.empty()) continue;

        if (arg == "-h" || arg == "--help") 
        {
            help();
            exit(0);
        }
        else if (arg == "-n" || arg == "--num-mode")
        {
            number_mode = true;
        }
        else if (arg == "-c" || arg == "--cmd-input")
        {
            input_from_args = true;
        }
        else 
        {
            if (input_from_args) input += arg + " ";
            std::runtime_error{"Unknown argument: " + arg};
        }
    }
    if (!input.empty()) input.pop_back();
}

} // namespace bf