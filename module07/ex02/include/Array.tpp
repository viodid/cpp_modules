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
    , _size(cp.size())
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
Array<T>& Array<T>::operator=(const Array& cp)
{
    if (&cp == this)
        return *this;
    delete[] _arr;
    _size = cp.size();
    _arr = new T(cp.size());
    for (unsigned int i = 0; i < cp.size(); i++) {
        _arr[i] = cp.getArr()[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw IndexOutOfBounds();
    return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
T* Array<T>::getArr() const
{
    return _arr;
}

template <typename T>
const char* Array<T>::Array::IndexOutOfBounds::what() const throw()
{
    return ("Index out of bounds!");
}
