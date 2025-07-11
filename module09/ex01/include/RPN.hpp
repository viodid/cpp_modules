#ifndef RPN_HPP
#define RPN_HPP

#define OPERATORS "+-/*"
#define OPERANDS "0123456789"

#include <ostream>
#include <stack>
#include <string>

#include "Lexer.hpp"

class RPN {
private:
    std::stack<float> _stack;

    t_list* _tokenizer(const std::string& ex);
    void _parseExpression(t_list* tokens);

public:
    RPN();
    ~RPN();
    RPN(const RPN& cp);
    RPN& operator=(const RPN& cp);

    const std::stack<float>& getStack() const;
    void calculateExpression(const std::string&);

    class ExceptionOverflow : public std::exception {
        virtual const char* what() const throw();
    };
    class ExceptionToken : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
