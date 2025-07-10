#include "../include/RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }

RPN::RPN(const RPN& cp)
{
    _stack = cp.getStack();
}

RPN& RPN::operator=(const RPN& cp)
{
    if (this != &cp)
        _stack = cp.getStack();
    return *this;
}
