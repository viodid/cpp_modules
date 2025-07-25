#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

typedef std::vector<unsigned int>::iterator t_it;

class PmergeMe {
private:
    std::vector<unsigned int> _vector;
    std::list<unsigned int> _list;
    unsigned int _executionTime;
    void _printExecTime(const std::string& container);

    void _parseInput(int, char**);
    void _printBefore();
    void _mergeInsertVector();
    void _mergeInsertVector(unsigned int depth);
    void _swapElements(t_it a, t_it b, unsigned int elemntSize);
    void _moveLabels(t_it* a, t_it* b, unsigned int elementSize, unsigned int block);
    void _moveBigLabel(t_it* l, unsigned int elementSize, unsigned int block);
    void _moveSmallLabel(t_it* l, unsigned int elementSize, unsigned int block);
    void _insertBoundElem(std::vector<unsigned int>&, t_it, unsigned int, unsigned int);
    void _eraseElement(t_it it, std::vector<unsigned int>& container, unsigned int elemSize);

public:
    PmergeMe();
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

#endif
