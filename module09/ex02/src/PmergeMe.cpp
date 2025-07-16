#include "../include/PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
    : _executionTime(0)
{
}

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& cp)
{
    (void)cp;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& cp)
{
    (void)cp;
    return *this;
}

void PmergeMe::sort(int argc, char** argv)
{
    _parseInput(argc, argv);
}

void PmergeMe::_parseInput(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i] && argv[i][0] == '0') {
            _list.push_back(0);
            _vector.push_back(0);
            continue;
        }
        int n = std::atoi(argv[i]);
        if (!n || n < 0)
            throw WrongInput();
        _list.push_back(n);
        _vector.push_back(n);
    }
}

void PmergeMe::_printBefore()
{
    std::cout << "Before:\t";
    std::vector<unsigned int>::iterator it;
    for (it = _vector.begin(); it != _vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printAfter()
{
    std::cout << "After:\t";
    std::vector<unsigned int>::iterator it;
    for (it = _vector.begin(); it != _vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::_printExecTime(const std::string& container)
{
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::" << container << ":"
              << _executionTime << " time order of magnitude" << std::endl;
}

// Exceptions

const char* PmergeMe::WrongInput::what() const throw()
{
    return "Error: input should be a positive integer";
}
