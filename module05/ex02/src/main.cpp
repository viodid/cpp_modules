#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
    AForm* f = new ShrubberyCreationForm("superfile");
    std::cout << *f << std::endl;
    Bureaucrat bob("Bob", 42);
    std::cout << bob << std::endl;
    bob.signForm(*f);
    bob.executeForm(*f);
    RobotomyRequestForm rf("Ford");
    std::cout << rf << std::endl;
    bob.signForm(rf);
    bob.executeForm(rf);
    PresidentialPardonForm pf("Marvin");
    std::cout << pf << std::endl;
    bob.signForm(pf);
    bob.executeForm(pf);
    Bureaucrat alice("Alice", 10);
    std::cout << alice << std::endl;
    alice.signForm(pf);
    alice.executeForm(pf);
    std::cout << "== DESTRUCTORS ==" << std::endl;
    delete f;
    return 0;
}
