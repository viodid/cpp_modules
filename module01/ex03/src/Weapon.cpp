#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string& weapon_type) : _type(weapon_type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() { return (_type); }

void Weapon::setType(const std::string& new_type) { _type = new_type; }
