#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <exception>
#include <vector>

class Span {
private:
    std::vector<int> _v;
    unsigned int _len;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& cp);
    ~Span();

    Span& operator=(const Span& cp);

    unsigned int getLen() const;
    void addNumber(unsigned int n);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    void insertVector(const std::vector<int> v);

    class NotFound : public std::exception {
        const char* what() const throw();
    };
    class LimitExceeded : public std::exception {
        const char* what() const throw();
    };
};

#endif
