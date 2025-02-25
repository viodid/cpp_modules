#include <Character.hpp>
#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

int main()
{
	Character alice;
	Character eve;
	ICharacter* bob = new Character("bob");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria *tmp;
	tmp = src->createMateria("ice");
	alice.equip(tmp);
	tmp = src->createMateria("cure");
	alice.equip(tmp);
	tmp = src->createMateria("ice");
	eve.equip(tmp);
	bob->unequip(3);
	bob->equip(tmp->clone());

	alice.use(0, eve);
	alice.use(1, eve);
	eve.use(0, eve);
	bob->use(0, alice);

	delete bob;
	delete src;

	return 0;
}
