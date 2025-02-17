#ifndef WRONGCAT_H
# define WRONGCAT_H
# include <WrongAnimal.hpp>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	~WrongCat();
	WrongCat& operator=(const WrongCat& obj);

	void makeSound() const;
};

#endif