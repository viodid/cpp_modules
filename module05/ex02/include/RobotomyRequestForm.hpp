#ifndef ROBOTOMY_H
#define ROBOTOMY_H

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

    const std::string& getTarget() const;
    void excecute(const Bureaucrat& executor) const;
};
#endif
