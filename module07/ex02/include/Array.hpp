#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    T _element;
    int size;

public:
    Array();
    Array(int n);
    Array(const Array& cp);
    ~Array();
    Array& operator=(const Array& cp);
};

#endif
