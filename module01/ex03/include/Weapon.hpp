#ifndef WEAPON_H
#define WEAPON_H

# include <string>
# include <iostream>

class Weapon
{
public:
	Weapon(const std::string& weapon_type);
	~Weapon();

	const std::string& getType();
	void setType(const std::string& new_type);

private:
	std::string _type;
};

#endif
