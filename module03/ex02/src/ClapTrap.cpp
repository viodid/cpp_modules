#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("defaul name")
    , _hitPoints(100)
    , _energyPoints(10)
    , _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
    : _name(obj.getName())
    , _hitPoints(obj.getHitPoints())
    , _energyPoints(obj.getEnergPoints())
    , _attackDamage(obj.getAttackDamage())
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name)
    , _hitPoints(100)
    , _energyPoints(10)
    , _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap does not have enough energy points!" << std::endl;
        return;
    }
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
    std::cout << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(const unsigned int amount)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
        return;
    }
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " has been attacked, receiving ";
    std::cout << amount << " points of damage!" << std::endl;

    std::cout << "ClapTrap now has " << _hitPoints << " heal points." << std::endl;
}

void ClapTrap::beRepaired(const unsigned int amount)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap does not have hit points, aborting!" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap does not have enough energy points!" << std::endl;
        return;
    }
    _energyPoints -= 1;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has been repaired " << amount << " points!" << std::endl;

    std::cout << "ClapTrap now has " << _hitPoints << " heal points." << std::endl;
}

void ClapTrap::decreaseEnergy()
{
    _energyPoints -= 1;
}

int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

int ClapTrap::getEnergPoints() const
{
    return _energyPoints;
}

std::string ClapTrap::getName() const
{
    return _name;
}
