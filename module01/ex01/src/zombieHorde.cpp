#include "../include/Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde(const int N, std::string name)
{
	if (N < 1)
	{
		std::cerr << "N should be a positive integer" << std::endl;
		std::exit(1);
	}
	Zombie* z_arr = new Zombie[N];

	for (int i = 0; i < N; i++)
		z_arr[i].set_name(name + static_cast<char>((i % 10) + 48));
	return (z_arr);
}
