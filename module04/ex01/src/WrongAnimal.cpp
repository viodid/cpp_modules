#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called." << std::endl;
	type = "wrong undefined";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong and weird animal sound..." << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (type);
}

