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

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
}
