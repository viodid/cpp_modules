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
    if (str.length() == 1 && std::isprint(str.c_str()[0]))
        return true;
    return false;
}

void ScalarConverter::convert(const std::string& str)
{
}
