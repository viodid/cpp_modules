#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("undefined", 145, 137)
    , _target("undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string& target)
    : AForm(name, 145, 137)
    , _target(target + "_shrubbery")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy.getName(), copy.getSignGrade(), copy.getExecuteGrade())
    , _target(copy.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm " << getName() << " destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if (this != &copy) {
        setSign(copy.isSigned());
    }
    return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
    return _target;
}

void ShrubberyCreationForm::excecute(const Bureaucrat& executor) const
{
    (void)executor;
    std::ofstream f;
    f.open(_target.c_str(), std::ios::out);
    f << "      /\\\n";
    f << "     /  \\\n";
    f << "    /____\\\n";
    f << "   /______\\\n";
    f << "  /________\\\n";
    f << "      ||\n";
    f << "      ||\n";
    f << "      ||\n";
    f << "      ||\n";
    f.close();
}
