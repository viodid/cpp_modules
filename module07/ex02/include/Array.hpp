#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    T* _arr;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& cp);
    ~Array();
    Array& operator=(const Array& cp);

    T& operator[](int i) const;
    unsigned int getSize() const;
    T* getArr() const;
};
#include "Array.cpp"

#endif
