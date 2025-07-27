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
    void _cpABToContainer(std::vector<unsigned int>& a, std::vector<unsigned int>& b);
    void _insertElements(t_v& main, t_v& pend, uint elemsToInsert, uint elementSize, uint jn);

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
