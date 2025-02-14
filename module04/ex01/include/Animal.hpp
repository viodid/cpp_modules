#ifndef ANIMAL_H
# define ANIMAL_H
#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string& getType() const;

protected:
	std::string type;
};

#endif