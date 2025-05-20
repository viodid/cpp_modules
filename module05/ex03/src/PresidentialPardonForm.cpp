#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential", 25, 5)
    , _target("undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("presidential", 25, 5)
    , _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade())
    , _target(copy.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm " << getName() << " destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this != &copy) {
        setSign(copy.isSigned());
    }
    return *this;
}

const std::string& PresidentialPardonForm::getTarget() const
{
    return _target;
}

void PresidentialPardonForm::excecute(const Bureaucrat& executor) const
{
    checkRequirements(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
