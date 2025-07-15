#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <list>
#include <vector>

class PmergeMe {
private:
    std::vector<unsigned int> _vector;
    std::list<unsigned int> _list;

    void _parseInput(int, char**);

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

#endif
