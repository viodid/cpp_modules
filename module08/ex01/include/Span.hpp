#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>
#include <exception>
#include <set>

class Span {
private:
    std::set<int> _s;
    unsigned int _len;

public:
    Span();
    Span(unsigned int n);
    Span(const Span& cp);
    ~Span();

    Span& operator=(const Span& cp);

    unsigned int getLen() const;

    class IndexOutOfBounds : public std::exception {
        const char* what() const throw();
    };
};

#endif
