#include "../include/PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return EXIT_FAILURE;
    t_v vector;
    PmergeMe<t_v> algoVector(vector);
    t_l list;
    PmergeMe<t_l> algoList(list);
    try {
        // Vector
        algoVector.parseInput(argc - 1, &argv[1]);
        algoVector.printContainer("Before:\t");
        algoVector.sort();
        algoVector.printContainer("After:\t");
        // List
        algoList.parseInput(argc - 1, &argv[1]);
        algoList.sort();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
