#include "../include/Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called." << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& obj)
    : AAnimal(obj)
{
    std::cout << "Dog copy constructor called." << std::endl;
    type = obj.type;
    _brain = new Brain(*obj.getBrain());
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog copy assignment operator called." << std::endl;
    type = obj.type;
    _brain = new Brain(*obj.getBrain());
    return *this;
}

Brain* Dog::getBrain() const
{
    return _brain;
}

void Dog::makeSound() const
{
    std::cout << "Guau, guau, *licking sounds*" << std::endl;
}

void Dog::showIdeas() const
{
    for (int i = 0; i < 100; i++) {
        std::cout << "idea: " << _brain->getIdeas()[i] << std::endl;
    }
}
