#include "../include/Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& obj)
    : Animal(obj)
{
    std::cout << "Cat copy constructor called." << std::endl;
    type = obj.type;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat copy assignment operator called." << std::endl;
    if (this != &obj)
        type = obj.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meowww, prrrrrr..." << std::endl;
}
