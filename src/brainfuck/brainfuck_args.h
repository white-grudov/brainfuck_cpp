#pragma once

#include <string>

namespace bf
{

struct BrainfuckArgs
{
    bool input_from_args;
    bool number_mode;

    std::string input;

    BrainfuckArgs() : input_from_args{false}, number_mode{false} {}
    BrainfuckArgs(bool input_from_args, bool number_mode) 
        : input_from_args{input_from_args}
        , number_mode{number_mode}
    {}

    void help() const noexcept;
    void parse(int argc, char** argv) ;
};

} // namespace bf