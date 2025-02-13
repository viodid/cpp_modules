#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "FragTrap does not have hit points, aborting!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "FragTrap does not have enough energy points!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << _name << " says: 'Gimme a high five!'" << std::endl;
}

