#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap();
    DiamondTrap(const DiamondTrap& obj);
    DiamondTrap(const std::string& name);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& obj);

    using ScavTrap::attack;
    void whoAmI() const;
    const std::string& getDiamondName() const;

private:
    std::string _name;
    using FragTrap::_attackDamage;
    using FragTrap::_hitPoints;
    using ScavTrap::_energyPoints;
};

#endif
