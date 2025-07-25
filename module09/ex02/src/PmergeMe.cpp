#include "../include/PmergeMe.hpp"

static unsigned int getJacobNum(unsigned int nu);

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
    // Step 1: recursive pairing & sorting
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
    // Step 2: relabel at each recursion level, create main and pend sequences
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    a = _vector.begin();
    // create head main sequence {b1, a1}
    for (unsigned int i = 0; i < elementSize * 2; i++) {
        main.push_back(*a);
        a++;
    }
    for (unsigned int block = 2; block <= (_vector.size() / (elementSize * 2)); block++) {
        // complete remaining main sequence {a2, a3...}
        _moveSmallLabel(&a, elementSize, block);
        a++;
        for (unsigned int i = 0; i < elementSize; i++) {
            main.push_back(*a);
            a++;
        }
        // create pend sequence {b2, b3...}
        _moveBigLabel(&b, elementSize, block - 1);
        b++;
        for (unsigned int i = 0; i < elementSize; i++) {
            pend.push_back(*b);
            b++;
        }
    }
    for (t_it it = a; it != _vector.end(); it++) {
        pend.push_back(*it);
    }
    // cp main and pend to main container
    // TODO: decouple logic with fn
    _vector.clear();
    for (t_it it = main.begin(); it != main.end(); it++) {
        _vector.push_back(*it);
    }
    for (t_it it = pend.begin(); it != pend.end(); it++) {
        _vector.push_back(*it);
    }
    // Step 3: find nth Jacobsthal number and insert element
    unsigned int jnSeq = 3;
    unsigned int jn = getJacobNum(jnSeq);
    unsigned int elemsToInsert = 2;
    unsigned int totalElemInsert = 0;
    while (elemsToInsert * elementSize <= pend.size()) {
        while (elemsToInsert > 0) {
            t_it it = pend.begin();
            std::advance(it, elemsToInsert * elementSize - 1);
            // insert element into main starting from bound limit
            _insertBoundElem(main, it, elementSize, jn + totalElemInsert + 1); // + 1 for the first {b1} main label
            _eraseElement(it, pend, elementSize);
            elemsToInsert--;
        }
        // TODO: insert remaining pend elemnts
        if (pend.size() > 0) { }
        totalElemInsert += elemsToInsert;
        jnSeq++;
        elemsToInsert = getJacobNum(jnSeq) - elemsToInsert;
        jn = getJacobNum(jnSeq);
    }

    // logging
    std::cout << "========" << std::endl;
    std::cout << "main=" << std::endl;
    printContainer(main);
    std::cout << "pend=" << std::endl;
    printContainer(pend);
    std::cout << "_vector=" << std::endl;
    printContainer(_vector);
}

void PmergeMe::_insertBoundElem(std::vector<unsigned int> main, t_it b_it, unsigned int elementSize, unsigned int elemOffset)
{
    t_it a_it = main.begin();
    if (elementSize * elemOffset >= main.size()) {
        a_it = main.end();
        a_it--;
    } else
        std::advance(a_it, elemOffset * elementSize);
    while (*b_it < *a_it) {
        std::advance(a_it, -elementSize);
    }
    a_it++;
    for (unsigned int i = 0; i < elementSize; i++) {
        a_it = main.insert(a_it, *b_it);
        b_it--;
    }
}

void PmergeMe::_eraseElement(t_it it, std::vector<unsigned int> container, unsigned int elemSize)
{
    for (unsigned int i = 0; i < elemSize; i++) {
        container.erase(it);
        it--;
    }
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

static unsigned int getJacobNum(unsigned int nu)
{
    return std::ceil((std::pow(2, nu) - std::pow(-1, nu)) / 3);
}
