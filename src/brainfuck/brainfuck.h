#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <optional>
#include <exception>

namespace bf
{

constexpr uint16_t CELL_COUNT = 32768;
constexpr const char* ERROR_MESSAGE = "Invalid character at input. Expected: \'+\', \'-\', \'<\', \'>\', \'[\', \']\', \'.\', \',\', got: ";

class brainfuck_error final : public std::exception
{
private:
    char error_ch;

public:
    brainfuck_error(char ch) : error_ch{ch} {}

    virtual const char* what() const throw()
    {
        return ERROR_MESSAGE + error_ch;
    }
};

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