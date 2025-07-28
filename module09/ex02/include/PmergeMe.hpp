#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

typedef std::vector<unsigned int>::iterator t_it;
typedef std::vector<unsigned int> t_v;
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
    void _swapElements(t_it a, t_it b, uint elemntSize);
    void _moveLabels(t_it* a, t_it* b, uint elementSize, uint block);
    void _moveBigLabel(t_it* l, uint elementSize, uint block);
    void _moveSmallLabel(t_it* l, uint elementSize, uint block);
    void _insertBoundElem(std::vector<uint>&, t_it, uint, uint);
    void _eraseElement(t_it it, std::vector<uint>& container, uint elemSize);
    void _cpABToContainer(std::vector<uint>& a, std::vector<uint>& b);
    void _insertElements(t_v& main, t_v& pend, uint elemsToInsert, uint elementSize, uint jn);
    uint _getJacobNum(unsigned int nu);

public:
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
