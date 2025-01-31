#ifndef HUMANA_H
#define HUMANA_H

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const Weapon& weapon, const std::string& name);
	~HumanA();

	void attack();

private:
	Weapon _weapon;
	std::string _name;
};

#endif
