#include "../include/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
    return *this;
}

AForm* Intern::makeShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& f_name, const std::string& f_target)
{
    int option = 0;
    AForm* (Intern::* forms[3])(const std::string&) = {
        &Intern::makeShrubberyForm,
        &Intern::makeRobotomyForm,
        &Intern::makePresidentialForm,
    };

    const std::string names[3] {
        "shrubbery",
        "robotomy",
        "presidential",
    };

    for (int i = 0; i < 3; i++) {
    }
}
