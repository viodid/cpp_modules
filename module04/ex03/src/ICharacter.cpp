#include <ICharacter.hpp>

ICharacter::ICharacter()
{
	std::cout << "ICharacter constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter&)
{
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter::~ICharacter()
{
	std::cout << "ICharacter destructor called" << std::endl;
}


