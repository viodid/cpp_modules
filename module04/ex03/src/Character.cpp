#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include <cstring>

Character::Character()
    : _name("")
{
    std::cout << "Character constructor called" << std::endl;
    _inventory = new AMateria*[4];
    std::memset(_inventory, 0, sizeof(AMateria*) * 4);
}

Character::Character(const std::string& name)
    : _name(name)
{
    std::cout << "Character constructor called" << std::endl;
    _inventory = new AMateria*[4];
    std::memset(_inventory, 0, sizeof(AMateria*) * 4);
}

Character::Character(const Character& obj)
    : _name(obj.getName())
{
    std::cout << "Character copy constructor called" << std::endl;
    _inventory = new AMateria*[4];
    std::memset(_inventory, 0, sizeof(AMateria*) * 4);
    for (int i = 0; i < 4; i++) {
        _inventory[i] = obj.getInventory()[i];
        if (_inventory[i] == NULL)
            break;
    }
}

Character& Character::operator=(const Character& obj)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    _name = obj.getName();
    for (int i = 0; i < 4; i++) {
        _inventory[i] = obj.getInventory()[i];
        if (_inventory[i] == NULL)
            break;
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL)
            continue;
        delete _inventory[i];
    }
    delete[] _inventory;
}

const std::string& Character::getName() const
{
    return _name;
}

AMateria** Character::getInventory() const
{
    return _inventory;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return;
    if (_inventory[idx] != NULL && _inventory[idx]->getType() == "ice")
        Ice().use(target);
    if (_inventory[idx] != NULL && _inventory[idx]->getType() == "cure")
        Cure().use(target);
}
