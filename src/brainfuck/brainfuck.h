#pragma once

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
    std::vector<uint8_t> cells;
    uint16_t current_index;
    uint16_t max_index;

    uint64_t current_char;

public:
    Brainfuck();
    ~Brainfuck() noexcept = default;

    std::string parse(std::string input);

private:
    std::optional<char> process_char(std::string& input);
    void reset() noexcept;
};

} // namespace bf