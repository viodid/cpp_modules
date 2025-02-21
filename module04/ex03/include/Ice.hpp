#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
protected:
	Ice(const Ice& obj);
	Ice& operator=(const Ice& obj);

public:
	Ice();
	~Ice();
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
