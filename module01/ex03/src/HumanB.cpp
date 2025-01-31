#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string& name) : _weapon(NULL),  _name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType();
}
