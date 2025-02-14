#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal, public Brain
{
public:
	Cat();
	~Cat();
	void makeSound() const;
};

#endif