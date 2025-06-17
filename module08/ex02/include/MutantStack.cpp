#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() { }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& cp)
{
    *this = cp;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& cp)
{
    if (this == &cp)
        return *this;
    *this = cp;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
