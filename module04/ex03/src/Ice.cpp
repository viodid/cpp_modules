#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"

Ice::Ice()
    : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& obj)
    : AMateria(obj.getType())
{
    std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& obj)
{
    std::cout << "Ice copy constructor called" << std::endl;
    _type = obj.getType();
    return *this;
}

AMateria* Ice::clone() const
{
    std::cout << "Ice clone mem func called" << std::endl;
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
