#include "../include/Weapon.hpp"

const std::string& Weapon::getType() { return (_type); }

void Weapon::setType(const std::string& new_type) { _type = new_type; }
