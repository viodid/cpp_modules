#include "../include/AForm.hpp"

AForm::AForm()
    : _name("undefined")
    , _signed(false)
    , _sign_grade(150)
    , _execute_grade(150)
{
}

AForm::AForm(const std::string& name, int sign_grade, int execute_grade)
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

AForm::AForm(const AForm& copy)
    : _name(copy.getName())
    , _signed(copy.isSigned())
    , _sign_grade(copy.getSignGrade())
    , _execute_grade(copy.getExecuteGrade())
{
}

AForm::~AForm()
{
    std::cout << "AForm " << _name << " destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy) {
        _signed = copy.isSigned();
    }
    return *this;
}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getSignGrade() const
{
    return _sign_grade;
}

int AForm::getExecuteGrade() const
{
    return _execute_grade;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > _sign_grade)
        throw AForm::GradeTooLowException();
    _signed = true;
}

// Exception classes
const char* AForm::AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high!");
}

const char* AForm::AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low!");
}

// Overload operator
std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "AForm: " << f.getName() << "\nIs it signed: " << f.isSigned()
        << "\nRequired grade to sign it: " << f.getSignGrade()
        << "\nRequired grade to execute it: " << f.getExecuteGrade() << std::endl;
    return out;
}
