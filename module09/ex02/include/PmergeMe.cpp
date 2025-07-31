#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe()
    : _container(NULL)
    , _executionTime(0)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(T container)
    : _container(container)
    , _executionTime(0)
{
}

template <typename T>
PmergeMe<T>::~PmergeMe() { }

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& cp)
{
    (void)cp;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& cp)
{
    (void)cp;
    return *this;
}

template <typename T>
void PmergeMe<T>::sort(int argc, char** argv)
{
    _parseInput(argc, argv);
    _printBefore();
    _mergeInsert(1);
    printContainer(_container);
}

template <typename T>
void PmergeMe<T>::_mergeInsert(uint depth)
{
    // Step 1: recursive pairing & sorting
    unsigned int elementSize = std::pow(2, depth - 1);
    if (elementSize > _container.size() / 2)
        return;
    t_it a = _container.begin();
    t_it b = _container.begin();
    for (unsigned int block = 1; block <= (_container.size() / (elementSize * 2)); block++) {
        _moveLabels(&a, &b, elementSize, block);
        if (*b > *a)
            _swapElements(a, b, elementSize);
    }
    std::cout << "depth=" << depth << std::endl;
    printContainer(_container);
    _mergeInsert(depth + 1);
    // Step 2: relabel at each recursion level, create main and pend sequences
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    a = _container.begin();
    // create head main sequence {b1, a1}
    for (unsigned int i = 0; i < elementSize * 2; i++) {
        main.push_back(*a);
        a++;
    }
    for (unsigned int block = 2; block <= (_container.size() / (elementSize * 2)); block++) {
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
    for (t_it it = a; it != _container.end(); it++) {
        pend.push_back(*it);
    }
    _cpABToContainer(main, pend);
    // Step 3: find nth Jacobsthal number and insert element
    unsigned int jnSeq = 3;
    unsigned int jn = _getJacobNum(jnSeq);
    unsigned int elemsToInsert = 2;
    while (elemsToInsert * elementSize <= pend.size()) {
        _insertElements(main, pend, elemsToInsert, elementSize, jn);
        jnSeq++;
        elemsToInsert = _getJacobNum(jnSeq) - jn;
        jn = _getJacobNum(jnSeq);
    }
    if (pend.size() >= elementSize) {
        elemsToInsert = std::floor(pend.size() / elementSize);
        _insertElements(main, pend, elemsToInsert, elementSize, jn);
    }
    _cpABToContainer(main, pend);

    // logging
    std::cout << "========" << std::endl;
    std::cout << "main=" << std::endl;
    printContainer(main);
    std::cout << "pend=" << std::endl;
    printContainer(pend);
    std::cout << "_container=" << std::endl;
    printContainer(_container);
}

template <typename T>
void PmergeMe<T>::_insertElements(t_v& main, t_v& pend, uint elemsToInsert, uint elementSize, uint jn)
{
    static uint totalElemInsert = 0;
    uint elemInsert = 0;
    while (elemsToInsert > 0 && std::floor(pend.size() / elementSize) > 0) {
        t_it it = pend.begin();
        std::advance(it, elemsToInsert * elementSize - 1);
        // insert element into main starting from bound limit
        _insertBoundElem(main, it, elementSize, (jn - elemInsert) + totalElemInsert + 1); // + 1 for the first {b1} main label
        _eraseElement(it, pend, elementSize);
        elemsToInsert--;
        elemInsert++;
        totalElemInsert++;
    }
}

template <typename T>
void PmergeMe<T>::_insertBoundElem(std::vector<unsigned int>& main, t_it b_it, unsigned int elementSize, unsigned int elemOffset)
{
    t_it a_it = main.begin();
    if (elementSize * elemOffset >= main.size()) {
        elemOffset = main.size() / elementSize;
        a_it = main.end();
        a_it--;
    } else
        std::advance(a_it, elemOffset * elementSize - 1);
    while (elemOffset > 0 && *b_it < *a_it) {
        std::advance(a_it, static_cast<int>(elementSize) * -1);
        elemOffset--;
    }
    a_it++;
    for (unsigned int i = 0; i < elementSize; i++) {
        a_it = main.insert(a_it, *b_it);
        b_it--;
    }
}

template <typename T>
void PmergeMe<T>::_eraseElement(t_it it, std::vector<unsigned int>& container, unsigned int elemSize)
{
    for (unsigned int i = 0; i < elemSize; i++) {
        container.erase(it);
        it--;
    }
}

template <typename T>
void PmergeMe<T>::_cpABToContainer(std::vector<unsigned int>& a, std::vector<unsigned int>& b)
{
    _container.clear();
    for (t_it it = a.begin(); it != a.end(); it++) {
        _container.push_back(*it);
    }
    for (t_it it = b.begin(); it != b.end(); it++) {
        _container.push_back(*it);
    }
}

template <typename T>
void PmergeMe<T>::_moveLabels(t_it* a, t_it* b, unsigned int elementSize, unsigned int block)
{
    _moveBigLabel(a, elementSize, block);
    _moveSmallLabel(b, elementSize, block);
}

template <typename T>
void PmergeMe<T>::_moveBigLabel(t_it* l, unsigned int elementSize, unsigned int block)
{
    *l = _container.begin();
    unsigned int bigIdx = block * elementSize * 2 - 1;
    std::advance(*l, bigIdx);
}

template <typename T>
void PmergeMe<T>::_moveSmallLabel(t_it* l, unsigned int elementSize, unsigned int block)
{
    *l = _container.begin();
    unsigned int bigIdx = block * elementSize * 2 - 1;
    unsigned int smallIdx = bigIdx - elementSize;
    std::advance(*l, smallIdx);
}

template <typename T>
void PmergeMe<T>::_swapElements(t_it a, t_it b, unsigned int elemntSize)
{
    for (unsigned int i = 0; i < elemntSize; i++) {
        std::iter_swap(a, b);
        a--;
        b--;
    }
}

template <typename T>
void PmergeMe<T>::_parseInput(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i] && argv[i][0] == '0') {
            _container.push_back(0);
            continue;
        }
        int n = std::atoi(argv[i]);
        if (!n || n < 0)
            throw WrongInput();
        _container.push_back(n);
    }
}

template <typename T>
void PmergeMe<T>::_printBefore()
{
    std::cout << "Before:\t";
    std::vector<unsigned int>::iterator it;
    for (it = _container.begin(); it != _container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::_printExecTime(const std::string& container)
{
    std::cout << "Time to process a range of " << _container.size()
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

template <typename T>
uint PmergeMe<T>::_getJacobNum(unsigned int nu)
{
    return std::ceil((std::pow(2, nu) - std::pow(-1, nu)) / 3);
}

// Exceptions
template <typename T>
const char* PmergeMe<T>::WrongInput::what() const throw()
{
    return "Error: input should be a positive integer";
}
