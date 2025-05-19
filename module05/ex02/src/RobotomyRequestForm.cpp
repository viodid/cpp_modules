#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Form", 72, 45)
    , _target("undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Form", 72, 45)
    , _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade())
    , _target(copy.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << getName() << " destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if (this != &copy) {
        setSign(copy.isSigned());
    }
    return *this;
}

const std::string& RobotomyRequestForm::getTarget() const
{
    return _target;
}

void RobotomyRequestForm::excecute(const Bureaucrat& executor) const
{
    if (isSigned() == false) {
        throw FormIsNotSigned();
    } else if (executor.getGrade() > getExecuteGrade()) {
        throw GradeTooLowException();
    }
    std::cout << "Drilling noises..." << std::endl;
    int r = std::rand();
    if (r % 2 == 0) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << "The robotomy of " << _target << " has failed" << std::endl;
    }
}
