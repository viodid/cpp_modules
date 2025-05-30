#ifndef SCALAR_H
#define SCALAR_H

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#define DIGITS "0123456789"

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cp);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& cp);

    static bool isChar(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isInf(const std::string& str);

    static void convertFromChar(const std::string& str);
    static void convertFromInt(const std::string& str);
    static void convertFromInf();

public:
    static void convert(const std::string& str);
};

#endif
