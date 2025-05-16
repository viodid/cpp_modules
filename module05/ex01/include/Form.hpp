#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _signed;
    const int _sign_grade;
    const int _execute_grade;

public:
    Form();
    Form(const std::string& name, int sign_grade, int execute_grade);
    Form(const Form& copy);
    ~Form();
    Form& operator=(const Form& copy);

    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat& b);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif
