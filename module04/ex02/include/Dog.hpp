#ifndef DOG_H
# define DOG_H
#include <Brain.hpp>
#include <AAnimal.hpp>

class Dog : public AAnimal
{
public:
	Dog();
	Dog(const Dog& obj);
	~Dog();
	Dog& operator=(const Dog& obj);
	void makeSound() const;
	Brain* getBrain() const;
	void showIdeas() const;
private:
	Brain* _brain;
};

#endif