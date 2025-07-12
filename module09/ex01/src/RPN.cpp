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

const std::stack<int>& RPN::getStack() const
{
    return _stack;
}

void RPN::calculateExpression(const std::string& e)
{
    Lexer l(e);
    t_token t = l.nextToken();
    while (t.type != END) {
        switch (t.type) {
        case ILEGAL:
            throw ExceptionToken();
        case NUMBER:
            _stack.push(std::atoi(t.literal.c_str()));
        case PLUS:
            _addition();
        case MINUS:
            _substraction();
        case SLASH:
            _division();
        case ASTERISK:
            _multiplication();
        }
        l.nextToken();
    }
}

const char* RPN::ExceptionOverflow::what() const throw()
{
    return "Error: overflow";
}

const char* RPN::ExceptionToken::what() const throw()
{
    return "Error: unknown token";
}

const char* RPN::IlegalOperation::what() const throw()
{
    return "Error: invalid expression";
}
