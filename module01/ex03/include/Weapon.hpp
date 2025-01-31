#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
public:
	Weapon();
	~Weapon();

	const std::string& getType();
	void setType(const std::string& new_type);

private:
	std::string _type;
};

#endif
