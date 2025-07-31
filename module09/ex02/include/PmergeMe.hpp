#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

typedef std::vector<unsigned int> t_v;
typedef std::list<unsigned int> t_l;
typedef unsigned int uint;

template <typename T>
class PmergeMe {
private:
    T _container;
    uint _executionTime;
    void _printExecTime(const std::string& container);

    void _parseInput(int, char**);
    void _printBefore();
    void _mergeInsertVector();
    void _mergeInsert(uint depth);
    void _swapElements(typename T::iterator a, typename T::iterator b, uint elemntSize);
    void _moveLabels(typename T::iterator* a, typename T::iterator* b, uint elementSize, uint block);
    void _moveBigLabel(typename T::iterator* l, uint elementSize, uint block);
    void _moveSmallLabel(typename T::iterator* l, uint elementSize, uint block);
    void _insertBoundElem(T&, typename T::iterator, uint, uint);
    void _eraseElement(typename T::iterator it, T& container, uint elemSize);
    void _cpABToContainer(T& a, T& b);
    void _insertElements(T& main, T& pend, uint elemsToInsert, uint elementSize, uint jn);
    uint _getJacobNum(unsigned int nu);

public:
    PmergeMe();
    PmergeMe(T container);
    ~PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);

    void sort(int, char**);

    class WrongInput : public std::exception {
        virtual const char* what() const throw();
    };
};

template <typename T>
void printContainer(T container);

#include "PmergeMe.cpp"

#endif
