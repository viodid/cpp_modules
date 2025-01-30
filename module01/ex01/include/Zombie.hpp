#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void announce(void) const;
	void set_name(const std::string& name);

private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
