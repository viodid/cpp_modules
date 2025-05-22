#ifndef SCALAR_H
#define SCALAR_H

#include <iostream>
#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cp);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& cp);

    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isFloat(const std::string& str);

public:
    static void convert(const std::string& str);
};

#endif
