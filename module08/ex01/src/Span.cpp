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
    if (_v.size() == _len)
        throw LimitExceeded();
    _v.push_back(n);
}
unsigned int Span::shortestSpan() const
{
    if (_len <= 1)
        throw NotFound();
    std::vector<int> cp = _v;
    std::sort(cp.begin(), cp.end());
    std::vector<int>::iterator it = cp.begin();
    int range = *(it + 1) - *it;
    for (it = cp.begin(); it != cp.end(); it++) {
        int exp = *(it + 1) - *it;
        if (exp < range)
            range = exp;
    }
    return abs(range);
}

unsigned int Span::longestSpan() const
{
    if (_len <= 1)
        throw NotFound();
    unsigned int smallest = *(std::min_element(_v.begin(), _v.end()));
    unsigned int largest = *(std::max_element(_v.begin(), _v.end()));
    return largest - smallest;
}

const char* Span::Span::NotFound::what() const throw()
{
    return ("Range cannot be found");
}

const char* Span::Span::LimitExceeded::what() const throw()
{
    return ("Size limit exceeded");
}
