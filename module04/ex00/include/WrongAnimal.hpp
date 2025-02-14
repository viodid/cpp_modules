#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H
#include <string>
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	void makeSound() const;
	const std::string& getType() const;

protected:
	std::string type;
};

#endif