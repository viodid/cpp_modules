#include "../include/ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Wrong number of args: "
                  << argv[0] << " [literal]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
