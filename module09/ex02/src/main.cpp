#include "../include/PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return EXIT_FAILURE;
    PmergeMe algo;
    try {
        algo.sort(argc - 1, &argv[1]);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
