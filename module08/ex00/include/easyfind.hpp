#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T t, int toBeFound);

class ValueNotFound : public std::exception {
    virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif
