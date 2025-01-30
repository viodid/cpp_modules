#include "../include/Zombie.hpp"

Zombie::Zombie() : _name("")
{
}

Zombie::~Zombie()
{
	std::cout << "deleting zombie " << _name << std::endl;
}

void Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(const std::string& name)
{
	_name = name;
}
