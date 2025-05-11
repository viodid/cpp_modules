#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("undefined")
    , _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, uint grade)
    : _name(name)
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException("Grade too high.");
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException("Grade too low.");
    }
}
