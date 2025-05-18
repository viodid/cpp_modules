#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
    AForm* f = new ShrubberyCreationForm("form-A", "superfile");
    std::cout << *f << std::endl;
    Bureaucrat bob("Bob", 42);
    f->excecute(bob);
    // Bureaucrat alice("Alice", 150);
    // std::cout << bob << std::endl;
    // std::cout << alice << std::endl;
    // try {
    //     bob.signForm(f);
    //     alice.signForm(f);
    // } catch (std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }
    delete f;
    return 0;
}
