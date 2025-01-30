#include "../include/Zombie.hpp"

Zombie::Zombie(const std::string& name) : _name(name)
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
