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
    return std::atoi(str.c_str()) != 0;
}

bool ScalarConverter::isDouble(const std::string& str)
{
    (void)str;
    return true;
}

void ScalarConverter::convert(const std::string& str)
{
    std::cout << isInt(str) << " - " << std::atoi(str.c_str());
}

// TODO: add tests
int main(void)
{
    return 0;
}
