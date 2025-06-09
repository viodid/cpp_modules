#ifndef EASYFIND_H
#define EASYFIND_H

#include <exception>
#include <string>

template <typename T>
T easyfind(T t, int n);

class ValueNotFound : public std::exception {
    virtual const char* what() const throw();
};

#endif
