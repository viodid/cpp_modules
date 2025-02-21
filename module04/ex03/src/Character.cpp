#include <Character.hpp>
#include <cstring>

Character::Character() : _name("")
{
	std::cout << "Character constructor called" << std::endl;
	_inventory = new AMateria*[4];
	std::memset(_inventory, 0, sizeof(AMateria*) * 4);
}

Character::Character(const std::string& name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
	_inventory = new AMateria*[4];
	std::memset(_inventory, 0, sizeof(AMateria*) * 4);
}

Character::Character(const Character& obj)
{
	std::cout << "Character copy constructor called" << std::endl;
	_name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = obj.getInventory()[i];
		if (_inventory[i] == NULL)
			break;
	}
}

Character& Character::operator=(const Character& obj)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	_name = obj.getName();
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = obj.getInventory()[i];
		if (_inventory[i] == NULL)
			break;
	}
	return *this;
}
