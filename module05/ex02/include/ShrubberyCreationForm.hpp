#ifndef SHRUBBERY_H
#define SHRUBBERY_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const std::string _name;
    const std::string _target;
    bool _signed;
    const int _sign_grade;
    const int _execute_grade;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& name, const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

    void excecute(const Bureaucrat& executor) const;
};
#endif
