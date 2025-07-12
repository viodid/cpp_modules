#include "../include/RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0]
                  << " [RPN expression]" << std::endl;
        return EXIT_FAILURE;
    }
    RPN rpn;
    rpn.calculateExpression(argv[1]);
    return EXIT_SUCCESS;
}
