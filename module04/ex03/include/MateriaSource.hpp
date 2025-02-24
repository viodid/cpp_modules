#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria** _inventory;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& obj);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const& type);
	AMateria** getInventory() const;

};

#endif
