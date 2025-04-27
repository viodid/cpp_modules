#include "../include/Character.hpp"
#include "../include/Cure.hpp"
#include "../include/Ice.hpp"
#include "../include/MateriaSource.hpp"

int main()
{
    Character alice("Alice");
    Character eve("Eve");
    ICharacter* bob = new Character("Bob");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* tmp;
    tmp = src->createMateria("cure");
    alice.equip(tmp);
    tmp = src->createMateria("cure");
    alice.equip(tmp);
    tmp = src->createMateria("cure");
    alice.equip(tmp);
    tmp = src->createMateria("cure");
    alice.equip(tmp);
    MateriaSource newMS;
    newMS.learnMateria(new Ice());
    AMateria* extra = newMS.createMateria("ice");
    alice.equip(extra);
    tmp = src->createMateria("ice");
    eve.equip(tmp);
    bob->unequip(3);
    bob->equip(tmp->clone());

    alice.use(0, *bob);
    alice.use(1, eve);
    alice.use(2, *bob);
    alice.use(3, eve);
    eve.use(0, eve);
    bob->use(0, alice);
    delete bob;
    delete src;
    delete extra;

    return 0;
}
