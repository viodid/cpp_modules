#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <ostream>
#include <stack>
#include <string>

#include "Lexer.hpp"

class RPN {
private:
    std::stack<int> _stack;

    void _parseExpression(t_list* tokens);

public:
    RPN();
    ~RPN();
    RPN(const RPN& cp);
    RPN& operator=(const RPN& cp);

    const std::stack<int>& getStack() const;
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
