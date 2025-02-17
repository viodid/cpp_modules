#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called." << std::endl;
	type = "wrong undefined";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	type = obj.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong and weird animal sound..." << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (type);
}

