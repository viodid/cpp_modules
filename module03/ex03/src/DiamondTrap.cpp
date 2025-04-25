#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name")
    , FragTrap("default_clap_name")
    , ScavTrap("default_clap_name")
    , _name("default")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name")
    , FragTrap(name + "_clap_name")
    , ScavTrap(name + "_clap_name")
    , _name(name)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
    : ClapTrap(obj)
    , FragTrap(obj)
    , ScavTrap(obj)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &obj) {
        _name = obj.getDiamondName();
        _hitPoints = obj.getHitPoints();
        _energyPoints = obj.getEnergPoints();
        _attackDamage = obj.getAttackDamage();
    }

    return *this;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap name: " << this->_name;
    std::cout << " - DiamondTrap ClapTrap name: " << ClapTrap::_name << std::endl;
}

const std::string& DiamondTrap::getDiamondName() const
{
    return _name;
}
