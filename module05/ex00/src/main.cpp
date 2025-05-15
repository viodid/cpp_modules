#include "../include/Bureaucrat.hpp"

int main(void)
{
    Bureaucrat bob("Bob", 42);
    Bureaucrat* alice = new Bureaucrat;
    std::cout << bob << std::endl;
    std::cout << *alice << std::endl;
    std::cout << "====" << std::endl;
    Bureaucrat ana("Ana", 1);
    try {
        ana.incremetGrade();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    ana.decrementGrade();
    ana.decrementGrade();
    std::cout << ana << std::endl;
    try {
        alice->decrementGrade();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    alice->incremetGrade();
    alice->incremetGrade();
    std::cout << *alice << std::endl;
    delete alice;
    try {
        Bureaucrat foo("Foo", 255);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
