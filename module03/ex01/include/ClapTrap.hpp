#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <string>
#include <ostream>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap(const std::string& name);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	const std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

#endif