#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <string>

typedef struct s_test {
    int n;
    std::string s;
} t_test;

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

    T& operator[](unsigned int i) const;
    unsigned int size() const;
    T* getArr() const;

    class IndexOutOfBounds : public std::exception {
        const char* what() const throw();
    };
};
#include "Array.cpp"

#endif
