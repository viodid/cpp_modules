#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("default")
{
    std::cout << "Scavtrap default constructor called" << std::endl;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
    : ClapTrap(obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this == &obj) {
        _name = obj.getName();
        _hitPoints = obj.getHitPoints();
        _energyPoints = obj.getEnergPoints();
        _attackDamage = obj.getAttackDamage();
    }

    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() <= 0) {
        std::cout << "ScavTrap does not have hit points, aborting!" << std::endl;
        return;
    }
    if (getEnergPoints() <= 0) {
        std::cout << "ScavTrap does not have enough energy points!" << std::endl;
        return;
    }
    decreaseEnergy();
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing ";
    std::cout << getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << getName() << " is in guard mode!" << std::endl;
}
