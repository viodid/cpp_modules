#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include <exception>

class Intern {
public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();
    Intern& operator=(const Intern& copy);

    AForm* makeForm(const std::string& name, const std::string& target);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
};

#endif
