#ifndef CLAPTRAP_H
# define CLAPTRAP_H
#include <string>
#include <ostream>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& obj);
	~ClapTrap();
    ClapTrap& operator=(const ClapTrap& obj);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
private:
	const std::string _name;
	int _hitPoints;
	int _energyPoints;
	const int _attackDamage;
};

#endif
