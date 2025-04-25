#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("default")
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj)
    : ClapTrap(obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this == &obj) {
        _name = obj.getName();
        _hitPoints = obj.getHitPoints();
        _energyPoints = obj.getEnergPoints();
        _attackDamage = obj.getAttackDamage();
    }

    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0) {
        std::cout << "FragTrap does not have hit points, aborting!" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
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
