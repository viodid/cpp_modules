#include "../include/HumanA.hpp"

HumanA::HumanA(const Weapon& weapon, const std::string& name) : _weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType();
}
