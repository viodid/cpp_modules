#include "../include/Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called." << std::endl;
    type = "undefined";
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal copy constructor called." << std::endl;
    type = obj.type;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal copy assignment operator called." << std::endl;
    if (this != &obj)
        type = obj.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Weird animal sound..." << std::endl;
}

const std::string& Animal::getType() const
{
    return (type);
}
