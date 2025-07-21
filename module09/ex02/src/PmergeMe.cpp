#include "../include/PmergeMe.hpp"

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
    _printBefore();
    _mergeInsertVector(1);
    // printContainer(_vector);
    // printContainer(_list);
}

void PmergeMe::_mergeInsertVector(unsigned int depth)
{
    unsigned int elementSize = std::pow(2, depth - 1);
    if (elementSize > _vector.size() / 2)
        return;
    t_it a = _vector.begin();
    t_it b = _vector.begin();
    for (unsigned int block = 1; block <= (_vector.size() / (elementSize * 2)); block++) {
        _moveLabels(&a, &b, elementSize, block);
        if (*b > *a)
            _swapElements(a, b, elementSize);
    }
    std::cout << "depth=" << depth << std::endl;
    printContainer(_vector);
    _mergeInsertVector(depth + 1);
    // step 2: relabel at each recursion level, create main and pend sequences
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    a = _vector.begin();
    for (unsigned int i = 0; i < elementSize * 2; i++) {
        main.push_back(*a);
        a++;
    }
    for (unsigned int block = 2; block <= (_vector.size() / (elementSize * 2)); block++) {
        _moveSmallLabel(&a, elementSize, block);
        a++;
        for (unsigned int i = 0; i < elementSize; i++) {
            main.push_back(*a);
            a++;
        }
    }
    // TODO: pend
    std::cout << "main=" << std::endl;
    printContainer(main);
    std::cout << "pend=" << std::endl;
    printContainer(pend);
}

void PmergeMe::_moveLabels(t_it* a, t_it* b, unsigned int elementSize, unsigned int block)
{
    _moveBigLabel(a, elementSize, block);
    _moveSmallLabel(b, elementSize, block);
}

void PmergeMe::_moveBigLabel(t_it* l, unsigned int elementSize, unsigned int block)
{
    *l = _vector.begin();
    unsigned int bigIdx = block * elementSize * 2 - 1;
    std::advance(*l, bigIdx);
}

void PmergeMe::_moveSmallLabel(t_it* l, unsigned int elementSize, unsigned int block)
{
    *l = _vector.begin();
    unsigned int bigIdx = block * elementSize * 2 - 1;
    unsigned int smallIdx = bigIdx - elementSize;
    std::advance(*l, smallIdx);
}

void PmergeMe::_swapElements(t_it a, t_it b, unsigned int elemntSize)
{
    for (unsigned int i = 0; i < elemntSize; i++) {
        std::iter_swap(a, b);
        a--;
        b--;
    }
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

void PmergeMe::_printExecTime(const std::string& container)
{
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::" << container << ":"
              << _executionTime << " time order of magnitude" << std::endl;
}

template <typename T>
void printContainer(T container)
{
    std::cout << "After:\t";
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Exceptions
const char* PmergeMe::WrongInput::what() const throw()
{
    return "Error: input should be a positive integer";
}
