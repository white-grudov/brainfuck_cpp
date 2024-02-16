#pragma once

#include <string>

namespace bf
{

struct BrainfuckArgs
{
    bool input_from_cmd;
    bool number_mode;

    std::string input;

    BrainfuckArgs() : input_from_cmd{false}, number_mode{false} {}

    void help() const noexcept;
    void parse(int argc, char** argv) ;
};

} // namespace bf