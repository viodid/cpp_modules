#include <cstring>
#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	_inventory = new AMateria*[4];
	memset(_inventory, 0, sizeof(AMateria*) * 4);
}

MateriaSource::MateriaSource(const MateriaSource&)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	// TODO
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "MateriaSource operator asssignemnt called" << std::endl;
}

void MateriaSource::learnMateria(AMateria*)
{

}

