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

const std::stack<float>& RPN::getStack() const
{
    return _stack;
}

void RPN::calculateExpression(const std::string& e)
{
    Lexer l(e);
    t_token t = l.nextToken();
    while (t.type != END) {
        switch (t.type) {
        case NUMBER:
            _stack.push(std::atoi(t.literal.c_str()));
            break;
        case PLUS:
            _calculateValue(&RPN::_addition);
            break;
        case MINUS:
            _calculateValue(&RPN::_substraction);
            break;
        case SLASH:
            _calculateValue(&RPN::_division);
            break;
        case ASTERISK:
            _calculateValue(&RPN::_multiplication);
            break;
        case ILEGAL:
            throw ExceptionToken();
        case END:
            return;
        }
        l.nextToken();
    }
}

/*
 * Retrieves the uppermost two operands
 * and takes a pointer to a mem func that calculates the value.
 * Finally, the calculated value is pushed back to the stack.
 */
void RPN::_calculateValue(float (RPN::*f)(float, float))
{
    if (_stack.size() < 2)
        throw IlegalOperation();
    float x = _stack.top();
    _stack.pop();
    float y = _stack.top();
    _stack.pop();
    _stack.push((this->*f)(x, y));
}

float RPN::_addition(float x, float y)
{
    return x + y;
}

float RPN::_substraction(float x, float y)
{
    return x - y;
}

float RPN::_multiplication(float x, float y)
{
    return x * y;
}

float RPN::_division(float x, float y)
{
    return x / y;
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
