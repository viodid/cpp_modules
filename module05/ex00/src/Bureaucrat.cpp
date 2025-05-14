#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("undefined")
    , _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) { }

void Bureaucrat::incremetGrade()
{
    if (_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

// Exception classes
const char* Bureaucrat::Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Bureaucrat::Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}
