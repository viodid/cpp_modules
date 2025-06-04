#include "Array.hpp"

template <typename T>
Array<T>::Array()
    : _arr(0)
    , _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : _arr(0)
    , _size(n)
{
    _arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& cp)
    : _arr(0)
    , _size(cp.getSize())
{
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _arr[i] = cp.getArr()[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] _arr;
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return _size;
}

template <typename T>
T* Array<T>::getArr() const
{
    return _arr;
}
