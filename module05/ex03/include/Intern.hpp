#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& copy);
    ~Intern();
    Intern& operator=(const Intern& copy);

    AForm* makeForm(const std::string& name, const std::string& target);
    AForm* makeShrubberyForm(const std::string& target);
    AForm* makeRobotomyForm(const std::string& target);
    AForm* makePresidentialForm(const std::string& target);
};

#endif
