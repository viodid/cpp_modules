#ifndef EASYFIND_H
#define EASYFIND_H

#include <exception>
#include <string>

template <typename T>
T easyfind(T t, int n)
{
    T e = t.begin();
    while (true) {
        if (e == t)
            break;
        if (e == t.end())
            throw;
        e = e++;
    }
    return t;
}

#endif
