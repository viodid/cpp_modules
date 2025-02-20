#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <string>

class AMateria
{
protected:
	std::string _type;
	AMateria();
	AMateria(const AMateria& obj);
	AMateria& operator=(const AMateria& obj);

public:
	AMateria(const std::string& type);
	~AMateria();

	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
