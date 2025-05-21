#ifndef SCALAR_H
#define SCALAR_H

#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cp);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& cp);

public:
    static void convert(std::string& literal);
};

#endif
