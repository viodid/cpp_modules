#ifndef ANIMAL_H
# define ANIMAL_H
#include <string>
#include <iostream>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal& obj);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal& obj);
	virtual void makeSound() const;
	const std::string& getType() const;

protected:
	std::string type;
};

#endif