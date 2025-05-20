#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "== BUREAUCRAT INITIALIZATION ==" << std::endl;
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;

    std::cout << "\n== SHRUBBERY FORM ==" << std::endl;
    AForm* f = new ShrubberyCreationForm("superfile");
    std::cout << *f << std::endl;
    bob.signForm(*f);
    bob.executeForm(*f);

    std::cout << "\n== ROBOTOMY FORM ==" << std::endl;
    RobotomyRequestForm rf("Ford");
    std::cout << rf << std::endl;
    bob.signForm(rf);
    bob.executeForm(rf);

    std::cout << "\n== PRESIDENTIAL FORM ==" << std::endl;
    PresidentialPardonForm pf("Marvin");
    std::cout << pf << std::endl;
    bob.signForm(pf);
    bob.executeForm(pf);
    Bureaucrat alice("Alice", 10);
    std::cout << alice << std::endl;
    alice.signForm(pf);
    alice.executeForm(pf);
    Bureaucrat vp("Vice President", 2);
    std::cout << vp << std::endl;
    vp.executeForm(pf);

    std::cout << "\n== INTERN ==" << std::endl;
    Intern* random = new Intern();
    random->makeForm("wrong form", "undefined");
    AForm* nf = random->makeForm("robotomy", "paul");
    alice.signForm(*nf);
    alice.executeForm(*nf);

    std::cout << "\n== DESTRUCTORS ==" << std::endl;
    delete f;
    delete random;
    delete nf;
    return 0;
}
