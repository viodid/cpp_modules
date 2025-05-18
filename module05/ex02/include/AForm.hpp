#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <exception>
#include <fstream>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _sign_grade;
    const int _execute_grade;

public:
    AForm();
    AForm(const std::string& name, int sign_grade, int execute_grade);
    AForm(const AForm& copy);
    virtual ~AForm();
    AForm& operator=(const AForm& copy);

    const std::string& getName() const;
    bool isSigned() const;
    void setSign(bool sign);
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(Bureaucrat& b);

    virtual void excecute(const Bureaucrat& executor) const = 0;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif
