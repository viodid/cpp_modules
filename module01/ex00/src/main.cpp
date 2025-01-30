#include "../include/Zombie.hpp"


int main(void)
{
	const Zombie* z = newZombie("HEAP");
	z->announce();
	delete z;
	randomChump("STACK");
	return (0);
}
