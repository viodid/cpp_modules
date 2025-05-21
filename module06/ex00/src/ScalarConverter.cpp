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
