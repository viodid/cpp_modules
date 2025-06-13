#include "../include/Span.hpp"

Span::Span() { }

Span::Span(unsigned int n)
    : _len(n)
{
}

Span::Span(const Span& cp)
    : _len(cp.getLen())
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& cp)
{
    if (&cp == this)
        return *this;
    _len = cp.getLen();
    return *this;
}

unsigned int Span::getLen() const
{
    return _len;
}

void Span::addNumber(unsigned int n)
{
    _v.push_back(n);
}
unsigned int Span::shortestSpan() const
{
    std::sort(_v.begin(), _v.end());
}

unsigned int Span::longestSpan() const
{
    unsigned int smallest = *(std::min_element(_v.begin(), _v.end()));
    unsigned int largest = *(std::max_element(_v.begin(), _v.end()));
    return largest - smallest;
}

const char* Span::Span::NotFound::what() const throw()
{
    return ("Index out of bounds!");
}
