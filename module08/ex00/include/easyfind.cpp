#include "easyfind.hpp"

template <typename T>
T easyfind(T t, int n)
{
    T e = t.begin();
    while (true) {
        if (e == t)
            break;
        if (e == t.end())
            throw ValueNotFound();
        e = e++;
    }
    return t;
}

const char* ValueNotFound::what() const throw()
{
    return "Value not found in container\n";
}
