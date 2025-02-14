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

void Animal::makeSound()
{
	std::cout << "Meowww, prrrrrr..." << std::endl;
}


