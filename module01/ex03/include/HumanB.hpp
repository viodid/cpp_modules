#ifndef HUMANB_H
#define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();

	void attack();
	void setWeapon(Weapon& new_weapon);

private:
	Weapon* _weapon;
	std::string _name;
};

#endif
