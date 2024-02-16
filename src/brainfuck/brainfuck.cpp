#include "brainfuck.h"
#include <algorithm>
#include <iostream>

namespace bf
{

Brainfuck::Brainfuck()
    : cells(CELL_COUNT, 0)
    , current_index{0}
    , max_index{0}
    , current_char{0}
{
}

std::string Brainfuck::parse(std::string input)
{
    reset();
    std::string result{};

    while (current_char < input.length())
    {
        if (auto ch = process_char(input)) result += *ch;
    }

    return result;
}

std::optional<char> Brainfuck::process_char(std::string& input)
{
    char ch = input[current_char];
    switch (ch)
    {
        case '>':
            current_index = (current_index + 1) % CELL_COUNT;
            break;
        case '<':
            current_index = (current_index - 1 + CELL_COUNT) % CELL_COUNT;
            break;
        case '+':
            ++cells[current_index];
            break;
        case '-':
            --cells[current_index];
            break;
        case '.':
            ++current_char;
            return cells[current_index];
        case ',':
            std::cin >> cells[current_index];
            break;
        case '[':
            if (!cells[current_index])
            {
                uint32_t non_matching = 0;
                while (input[current_char] != ']' && !non_matching)
                {
                    ++current_char;
                    if (input[current_char] == '[') ++non_matching;
                    if (input[current_char] == ']') --non_matching;
                }
            }
            break;
        case ']':
            if (cells[current_index])
            {
                uint32_t non_matching = 0;
                while (input[current_char] != '[' && !non_matching)
                {
                    --current_char;
                    if (input[current_char] == '[') ++non_matching;
                    if (input[current_char] == ']') --non_matching;
                }
            }
            break;
        default:
            throw brainfuck_error{ch};
    }
    ++current_char;
    return std::nullopt;
}

void Brainfuck::reset() noexcept
{
    std::fill(cells.begin(), cells.begin() + max_index, 0); // clear cells before the next program
    current_index = 0;
    current_char = 0;
}

} // namespace bf