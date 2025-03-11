#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
public:
	Zombie(const std::string& name);
	~Zombie();

	void announce(void) const;

private:
	std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
