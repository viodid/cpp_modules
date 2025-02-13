#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(const std::string& name);
	~DiamondTrap();

	using ScavTrap::attack;
	void whoAmI() const;
private:
	const std::string _name;
	using FragTrap::_hitPoints;
	using ScavTrap::_energyPoints;
	using FragTrap::_attackDamage;
};

#endif