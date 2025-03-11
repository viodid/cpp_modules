#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string& name) : _weapon(NULL), _name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (!_weapon) {
        std::cout << "There is no weapon! :O" << std::endl;
        return ;
    }

	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon* new_weapon) { _weapon = new_weapon; }
