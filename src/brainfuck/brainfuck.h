#pragma once

#include "brainfuck_args.h"
#include "brainfuck_exceptions.h"

#include <cstdint>
#include <vector>
#include <string>
#include <optional>

namespace bf
{

constexpr uint16_t CELL_COUNT = 32768;

class Brainfuck
{
private:
    BrainfuckArgs args;

    std::vector<uint8_t> cells;
    uint16_t current_index;
    uint16_t max_index;

    uint64_t current_char;

public:
    Brainfuck(const BrainfuckArgs& args);
    ~Brainfuck() noexcept = default;

    std::string parse(std::string input);

private:
    std::optional<char> process_char(std::string& input);
    void process_input();
    void reset() noexcept;
};

} // namespace bf