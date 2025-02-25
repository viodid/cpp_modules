#include <Cure.hpp>

#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
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

Cure& Cure::operator=(const Cure& obj)
{
	std::cout << "Cure copy constructor called" << std::endl;
	_type = obj.getType();
	return *this;
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone mem func called" << std::endl;
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

