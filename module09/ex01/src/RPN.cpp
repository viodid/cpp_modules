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

void RPN::_parseExpression(t_list* tokens)
{
    for (t_list* node = tokens; node != NULL; node = node->next) {
        t_token* t = (t_token*)node->content;
        if (t->type == OPERAND)
            _stack.push(4.42);
        // else if (t->type == OPERATOR)
        // _calculate
    }
}

t_list* RPN::_nextToken(const std::string& ex)
{

    while (eatWhitespace()) {
    }
}

void RPN::calculateExpression(const std::string& ex)
{
    t_list* tokens = _tokenizer(ex);
    // free_list(tokens);
}

const char* RPN::ExceptionOverflow::what() const throw()
{
    return "Error: overflow";
}

const char* RPN::ExceptionToken::what() const throw()
{
    return "Error: token unknown";
}
