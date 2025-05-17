#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
    Form f("form-A", 42, 10);
    std::cout << f << std::endl;
    Bureaucrat bob("Bob", 42);
    Bureaucrat alice("Alice", 150);
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    try {
        bob.signForm(f);
        alice.signForm(f);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
