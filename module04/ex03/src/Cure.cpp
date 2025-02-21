#include <Cure.hpp>

#include "ICharacter.hpp"

Cure::Cure() : AMateria("ice")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj.getType())
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& obj) : AMateria(obj.getType())
{
	std::cout << "Cure copy constructor called" << std::endl;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

