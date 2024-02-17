#include "brainfuck.h"

#include <algorithm>
#include <iostream>

namespace bf
{

Brainfuck::Brainfuck(const BrainfuckArgs& args)
    : args{args}
    , cells(CELL_COUNT, 0)
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
        if (auto ch = process_char(input)) 
        {
            result += args.number_mode ? std::to_string(static_cast<uint8_t>(*ch)) : std::string{*ch};
        }
    }

    return result;
}

std::optional<char> Brainfuck::process_char(std::string& input)
{
    char ch{input[current_char]};
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
            process_input();
            break;
        case '[':
            if (!cells[current_index])
            {
                uint32_t non_matching{0};
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
                uint32_t non_matching{0};
                while (input[current_char] != '[' && !non_matching)
                {
                    --current_char;
                    if (input[current_char] == '[') ++non_matching;
                    if (input[current_char] == ']') --non_matching;
                }
            }
            break;
        default:
            throw invalid_character_error{ch};
    }
    ++current_char;
    return std::nullopt;
}

void Brainfuck::process_input()
{
    if (args.input_from_args && args.input.empty())
    {
        throw empty_input_error{};
    }

    if (!args.input_from_args && !args.number_mode)
    {
        std::cin >> cells[current_index];
    }
    else if (args.input_from_args && !args.number_mode)
    {
        cells[current_index] = args.input[0];
        args.input = args.input.substr(1);
    }
    else
    {
        std::string num_str{};
        if (args.input_from_args)
        {
            if (auto pos = args.input.find(' '); pos != std::string::npos) 
            {
                num_str = args.input.substr(0, pos);
                args.input = args.input.substr(pos + 1);
            } 
            else 
            {
                num_str = args.input;
                args.input.clear();
            }
        }
        else std::cin >> num_str;

        try
        {
            int num = std::stoi(num_str.c_str());
            if (num < 0 || num > 255) throw std::out_of_range{""};
            cells[current_index] = static_cast<uint8_t>(num);
        }
        catch (const std::exception& e)
        {
            throw parse_number_error{num_str};
        }
    }
}

void Brainfuck::reset() noexcept
{
    std::fill(cells.begin(), cells.begin() + max_index, 0); // clear cells before the next program
    current_index = 0;
    current_char = 0;
}


} // namespace bf