#include "../include/ClapTrap.hpp"

int main()
{
    ClapTrap anon("anon");
    ClapTrap Bob(anon);
    Bob.attack("hey");
    anon.attack("someone");
    anon.beRepaired(3);
    anon.takeDamage(12);
    anon.attack("another one");
    anon.takeDamage(1);
    anon.beRepaired(10);
    return 0;
}
