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

	void attack(const std::string& target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	const std::string _name;
	int _hitPoints = 10;
	int _energyPoints = 10;
	const int _attackDamage = 0;
};

#endif