#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
