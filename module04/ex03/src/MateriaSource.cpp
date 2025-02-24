#include <cstring>
#include <MateriaSource.hpp>

#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	_inventory = new AMateria*[4];
	memset(_inventory, 0, sizeof(AMateria*) * 4);
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	_inventory = new AMateria*[4];
	std::memset(_inventory, 0, sizeof(AMateria*) * 4);
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = obj.getInventory()[i];
		if (_inventory[i] == NULL)
			break;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
			continue;
		delete _inventory[i];
	}
	delete _inventory;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "MateriaSource operator asssignemnt called" << std::endl;
	_inventory = new AMateria*[4];
	std::memset(_inventory, 0, sizeof(AMateria*) * 4);
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = obj.getInventory()[i];
		if (_inventory[i] == NULL)
			break;
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
			continue;
		_inventory[i] = materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
		{
			if (type == "ice")
				return new Ice();
			if (type == "cure")
				return new Cure();
		}
	}
	return 0;
}


AMateria** MateriaSource::getInventory() const
{
	return _inventory;
}


