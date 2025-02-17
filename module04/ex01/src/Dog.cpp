#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called." << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called." << std::endl;
	type = obj.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& obj)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	type = obj.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Guau, guau, *licking sounds*" << std::endl;
}
