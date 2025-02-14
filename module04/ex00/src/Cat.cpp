#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called." << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meowww, prrrrrr..." << std::endl;
}


