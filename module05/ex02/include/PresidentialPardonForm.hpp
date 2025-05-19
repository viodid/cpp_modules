#ifndef PRESIDENTIAL_H
#define PRESIDENTIAL_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

    const std::string& getTarget() const;
    void excecute(const Bureaucrat& executor) const;
};
#endif
