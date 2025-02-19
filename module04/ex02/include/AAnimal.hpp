#ifndef ANIMAL_H
# define ANIMAL_H
#include <string>
#include <iostream>

class AAnimal
{
public:
	virtual ~AAnimal();
	virtual void makeSound() const = 0; // this pure virtual member func makes the class abstract
	const std::string& getType() const;

protected:
	AAnimal();
	AAnimal(const AAnimal& obj);
	AAnimal& operator=(const AAnimal& obj);
	std::string type;
};

#endif