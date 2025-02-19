#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called." << std::endl;
	type = "undefined";
}

AAnimal::AAnimal(const AAnimal& obj)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
	type = obj.type;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	type = obj.type;
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "Weird animal sound..." << std::endl;
}

const std::string& AAnimal::getType() const
{
	return (type);
}

