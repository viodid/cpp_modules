#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T t, int toBeFound)
{
    typename T::iterator it;
    it = std::find(t.begin(), t.end(), toBeFound);
    if (it == t.end())
        throw ValueNotFound();
    return it;
}

const char* ValueNotFound::what() const throw()
{
    return "Value not found in container";
}

#endif
