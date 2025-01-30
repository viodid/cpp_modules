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

#endif
