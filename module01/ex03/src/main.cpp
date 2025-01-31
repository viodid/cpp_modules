#include "../include/Zombie.hpp"


int main(void)
{
	const int n = 10;
	const Zombie* arr_z = zombieHorde(n, "prettyZombieName");
	for (int i = 0; i < n; i++)
		arr_z[i].announce();
	delete[] arr_z;
	return (0);
}
