#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string& name);
	~FragTrap();

	void attack(const std::string& target);
	void highFivesGuys() const;
};

#endif
