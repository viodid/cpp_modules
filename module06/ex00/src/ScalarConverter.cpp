#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter& cp)
{
    *this = cp;
}

ScalarConverter::~ScalarConverter() { }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cp)
{
    if (this == &cp)
        *this = cp;
    return *this;
}

bool ScalarConverter::isChar(const std::string& str)
{
    return str.length() == 1 && std::isalpha(str.c_str()[0]);
}

bool ScalarConverter::isInt(const std::string& str)
{
    bool signal = false;
    if (str[0] == '-')
        signal = true;
    return str.find_first_not_of(DIGITS, signal) == str.npos;
}

bool ScalarConverter::isDouble(const std::string& str)
{
    size_t dot = str.find('.');
    if (dot == str.npos)
        return false;
    if (!isInt(str.substr(0, dot))
        || !isInt(str.substr(dot + 1, str.size())))
        return false;
    return true;
}

void ScalarConverter::convert(const std::string& str)
{
    std::cout << "isInt:\t\t" << isInt(str) << std::endl;
    std::cout << "isDouble:\t" << isDouble(str) << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./test <str>" << std::endl;
        exit(EXIT_FAILURE);
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
