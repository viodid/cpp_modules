#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : _name("undefined")
    , _target("undefined")
    , _signed(false)
    , _sign_grade(145)
    , _execute_grade(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target)
    : _name(name)
    , _target(target)
    , _signed(false)
    , _sign_grade(145)
    , _execute_grade(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : _name(copy.getName())
    , _signed(copy.isSigned())
    , _sign_grade(copy.getSignGrade())
    , _execute_grade(copy.getExecuteGrade())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm " << _name << " destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if (this != &copy) {
        _signed = copy.isSigned();
    }
    return *this;
}

void ShrubberyCreationForm::excecute(const Bureaucrat& executor) const
{
}
