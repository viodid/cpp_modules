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
    if (str.size() - signal == 0)
        return false;
    return str.find_first_not_of(DIGITS, signal) == str.npos;
}

bool ScalarConverter::isDouble(const std::string& str)
{
    size_t dot = str.find('.');
    if (dot == str.npos)
        return false;
    if (str[dot + 1] == '-')
        return false;
    if (!isInt(str.substr(0, dot))
        || !isInt(str.substr(dot + 1, str.size())))
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
    if (!isDouble(str.substr(0, str.size() - 1)))
        return false;
    return str[str.size() - 1] == 'f';
}

bool ScalarConverter::isInf(const std::string& str)
{
    if (str == "-inff" || str == "+inff"
        || str == "nanf" || str == "-inf"
        || str == "+inf" || str == "nan")
        return true;
    return false;
}

void ScalarConverter::convertFromChar(const std::string& str)
{
    if (std::isprint(str[0]))
        std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
    else
        std::cout << "char: " << "non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    std::cout << "isChar:\t\t" << isChar(str) << std::endl;
    std::cout << "isInt:\t\t" << isInt(str) << std::endl;
    std::cout << "isDouble:\t" << isDouble(str) << std::endl;
    std::cout << "isFloat:\t" << isFloat(str) << std::endl;
    std::cout << "isInf:\t\t" << isInf(str) << std::endl;
    if (isChar(str))
        convertFromChar(str);
    else if (isInf(str))
        convertFromInt(str);
    else
        convertFromInt(str);
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
