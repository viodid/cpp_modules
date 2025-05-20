#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy", 72, 45)
    , _target("undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("robotomy", 72, 45)
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
    checkRequirements(executor);
    std::cout << "Drilling noises..." << std::endl;
    std::srand(std::time(0));
    int r = std::rand();
    if (r % 2 == 0) {
        std::cout << _target << " has been robotomized" << std::endl;
    } else {
        std::cout << "The robotomy of " << _target << " has failed" << std::endl;
    }
}
