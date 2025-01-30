#include "../include/Zombie.hpp"

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

int main(void)
{
	const Zombie* z = newZombie("HEAP");
	z->announce();
	delete z;
	randomChump("STACK");
	return (0);
}
