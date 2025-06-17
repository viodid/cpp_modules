#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
    typedef typename std::deque<T>::iterator iterator;

    MutantStack();
    MutantStack(const MutantStack& cp);
    ~MutantStack();

    MutantStack& operator=(const MutantStack& cp);

    iterator begin();
    iterator end();
};

#include "MutantStack.cpp"

#endif
