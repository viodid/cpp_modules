#ifndef SHRUBBERY_H
#define SHRUBBERY_H

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

    const std::string& getTarget() const;
    void excecute(const Bureaucrat& executor) const;
};
#endif
