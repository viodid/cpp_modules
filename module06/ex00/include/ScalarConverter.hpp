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

public:
    static void convert(const std::string& literal);
};

#endif
