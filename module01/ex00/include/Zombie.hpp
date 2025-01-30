#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <string>

class Zombie
{
public:
	Zombie(const std::string& name);
	~Zombie();

private:
	std::string _name;
};


#endif
