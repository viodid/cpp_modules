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

void RPN::parseExpression(const std::string&)
{
}

const char* RPN::ExceptionOverflow::what() const throw()
{
    return "Error: overflow";
}

const char* RPN::ExceptionToken::what() const throw()
{
    return "Error: token unknown";
}
