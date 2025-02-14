#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called." << std::endl;
	type = "undefined";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Weird animal sound..." << std::endl;
}

const std::string& Animal::getType() const
{
	return (type);
}

