#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

#include "Lexer.hpp"

class RPN {
private:
    std::stack<float> _stack;

    float _parseExpression(t_list* tokens);
    float _addition(float, float);
    float _substraction(float, float);
    float _multiplication(float, float);
    float _division(float, float);
    void _calculateValue(float (RPN::*f)(float, float));

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
    class IlegalOperation : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
