#ifndef ANIMAL_H
# define ANIMAL_H
#include <string>
#include <iostream>

class Animal
{
public:
	virtual ~Animal();
	virtual void makeSound() const;
	const std::string& getType() const;

protected:
	Animal();
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	std::string type;
};

#endif