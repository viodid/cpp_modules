#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << this->_name;
	std::cout << " - DiamondTrap ClapTrap name: " << ClapTrap::_name << std::endl;
}
