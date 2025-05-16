#include "../include/Form.hpp"

Form::Form()
    : _name("undefined")
    , _signed(false)
    , _sign_grade(150)
    , _execute_grade(150)
{
}

Form::Form(const std::string& name, int sign_grade, int execute_grade)
    : _name(name)
    , _signed(false)
    , _sign_grade(sign_grade)
    , _execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (sign_grade > 150 || execute_grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Form::Form(const Form& copy)
    : _name(copy.getName())
    , _signed(copy.isSigned())
    , _sign_grade(copy.getSignGrade())
    , _execute_grade(copy.getExecuteGrade())
{
}

Form::~Form()
{
    std::cout << "Form " << _name << " destructor called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    if (this != &copy) {
        _signed = copy.isSigned();
    }
    return *this;
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getSignGrade() const
{
    return _sign_grade;
}

int Form::getExecuteGrade() const
{
    return _execute_grade;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > _sign_grade)
        throw Form::GradeTooLowException();
    _signed = true;
}

// Exception classes
const char* Form::Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* Form::Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

// Overload operator
std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form: " << f.getName() << "\nIs it signed: " << f.isSigned()
        << "\nRequired grade to sign it: " << f.getSignGrade()
        << "\nRequired grade to execute it: " << f.getExecuteGrade() << std::endl;
    return out;
}
