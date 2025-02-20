#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include "AMateria.hpp"

class ICharacter
{
protected:
	AMateria** _inventory;

	ICharacter();
	ICharacter(const ICharacter& obj);
	ICharacter& operator=(const ICharacter& obj);
public:
	virtual ~ICharacter();
	virtual const std::string& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual  void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif
