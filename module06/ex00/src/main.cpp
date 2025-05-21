#include "../include/ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Wrong number of args: "
                  << argv[0] << " [literal]"
                  << std::endl;
    }
    std::string str = argv[1];
    ScalarConverter::convert(str);
    return 0;
}
