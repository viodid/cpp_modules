#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : _name("undefined")
    , _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
    , _grade(grade)
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    : _name(copy.getName())
    , _grade(copy.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    if (this != &copy)
        _grade = copy.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incremetGrade()
{
    if (_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(AForm& f)
{
    try {
        f.beSigned(*this);
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
        return;
    }
    std::cout << _name << " signed " << f.getName() << std::endl;
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

// Overload operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return out;
}
