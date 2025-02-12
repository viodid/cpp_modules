#include "../include/ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name) : _name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap does not have enough energy points!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(const unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " has been attacked, receiving ";
	std::cout << amount << " points of damage!" << std::endl;

	std::cout << "ClapTrap now has " << _hitPoints << "heal points.";
}

void ClapTrap::beRepaired(const unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap does not have enough energy points!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " has been repaired " << amount << " points!" << std::endl;

	std::cout << "ClapTrap now has " << _hitPoints << "heal points.";
}
