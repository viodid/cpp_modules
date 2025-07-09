#ifndef RPN_HPP
#define RPN_HPP

#include <ostream>
#include <stack>
#include <string>

class RPN {
private:
    std::stack<float> _stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN& cp);
    RPN& operator=(const RPN& cp);

    void parseExpression(const std::string&);

    class ExceptionOverflow : public std::exception {
        virtual const char* what() const throw();
    };
    class ExceptionToken : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif
