#include <AMateria.hpp>

AMateria::AMateria() : _type("")
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	_type = obj.getType();
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	_type = obj.getType();
	return *this;
}

const std::string& AMateria::getType() const
{
	return _type;
}
