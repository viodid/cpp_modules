#ifndef DOG_H
# define DOG_H
#include "Animap.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void makeSound() override;
};

#endif