#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& obj);
	~ScavTrap();
    ScavTrap& operator=(const ScavTrap& obj);

	void attack(const std::string& target);
	void guardGate() const ;
};

#endif
