#include <Character.hpp>

Character::Character() : _name("")
{
	std::cout << "Character constructor called" << std::endl;
	_inventory = new AMateria*;
	*_inventory = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	_inventory = new AMateria*;
	*_inventory = NULL;

}

