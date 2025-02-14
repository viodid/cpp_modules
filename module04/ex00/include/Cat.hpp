#ifndef CAT_H
# define CAT_H
# include "Animap.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	void makeSound() override;
};

#endif