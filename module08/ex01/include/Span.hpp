#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <string>

template <typename T>
class Span {
private:
    T* _arr;
    unsigned int _size;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& cp);
    ~Span();

    Span& operator=(const Span& cp);

    T& operator[](unsigned int i) const;
    unsigned int size() const;
    T* getArr() const;

    class IndexOutOfBounds : public std::exception {
        const char* what() const throw();
    };
};
#include "Span.cpp"

#endif
