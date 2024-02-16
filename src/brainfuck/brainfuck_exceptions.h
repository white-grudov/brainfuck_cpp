#pragma once

#include <exception>
#include <string>

constexpr const char* INVALID_CHAR_MSG = "Invalid character at input. Expected: \'+\', \'-\', \'<\', \'>\', \'[\', \']\', \'.\', \',\', got: ";
constexpr const char* EMPTY_INPUT_MSG = "Not enough input data was provided for the program.";
constexpr const char* PARSE_NUM_MSG = "Expected a numeric byte value, got instead: ";

namespace bf
{

class brainfuck_error : public std::exception {};

class invalid_character_error final : public brainfuck_error
{
private:
    char error_ch;
    std::string error_str;

public:
    invalid_character_error(char ch) : error_ch{ch}, error_str{INVALID_CHAR_MSG} { error_str += error_ch; }

    virtual const char* what() const throw()
    {
        return error_str.c_str();
    }
};

class empty_input_error final : public brainfuck_error
{

public:
    empty_input_error() {}

    virtual const char* what() const throw()
    {
        return EMPTY_INPUT_MSG;
    }
};

class parse_number_error final : public brainfuck_error
{
private:
    std::string error_input;
    std::string error_str;

public:
    parse_number_error(std::string input) : error_input{input}, error_str{PARSE_NUM_MSG} { error_str += error_input; }

    virtual const char* what() const throw()
    {
        return error_str.c_str();
    }
};

}