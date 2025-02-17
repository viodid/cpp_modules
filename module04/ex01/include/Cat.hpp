#ifndef CAT_H
# define CAT_H
# include <Animal.hpp>
# include <Brain.hpp>

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat& obj);
	~Cat();
	Cat& operator=(const Cat& obj);
	void makeSound() const;
private:
	Brain* _brain;
};

#endif