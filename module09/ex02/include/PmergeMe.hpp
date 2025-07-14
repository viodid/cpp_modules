#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

class PmergeMe {
private:
    std::vector<unsigned int> _vector;
    std::list<unsigned int> _list;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);

    void sort(const std::string&);
};

#endif
