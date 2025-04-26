#include "../include/Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called." << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& obj)
    : Animal(obj)
{
    std::cout << "Cat copy constructor called." << std::endl;
    type = obj.type;
    _brain = new Brain(*obj.getBrain());
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat copy assignment operator called." << std::endl;
    type = obj.type;
    _brain = new Brain(*obj.getBrain());
    return *this;
}

Brain* Cat::getBrain() const
{
    return _brain;
}

void Cat::makeSound() const
{
    std::cout << "Meowww, prrrrrr..." << std::endl;
}

void Cat::showIdeas() const
{
    for (int i = 0; i < 100; i++) {
        std::cout << "idea: " << _brain->getIdeas()[i] << std::endl;
    }
}
