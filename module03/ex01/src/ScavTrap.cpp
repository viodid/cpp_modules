#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_hitPoints = ScavTrap.getHitPoints();
	_energyPoints = ScavTrap.getEnergyPoints();
	_attackDamage = ScavTrap.getAttackDamage();
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) : ClapTrap(obj.getName())
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
	_hitPoints = ScavTrap.getHitPoints();
	_energyPoints = ScavTrap.getEnergyPoints();
	_attackDamage = ScavTrap.getAttackDamage();
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap does not have hit points, aborting!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap does not have enough energy points!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << _name << " is in guard mode!" << std::endl;
}

