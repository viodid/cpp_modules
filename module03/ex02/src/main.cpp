#include "../include/FragTrap.hpp"
#include "../include/ScavTrap.hpp"

int main()
{
    ScavTrap fidson("fidson");
    fidson.takeDamage(13);
    ScavTrap bob(fidson);
    bob.takeDamage(1);
    FragTrap anon("anon");
    anon.attack("someone");
    fidson.attack("a poor guy");
    anon.beRepaired(3);
    anon.takeDamage(12);
    anon.attack("another one");
    anon.takeDamage(1);
    anon.beRepaired(10);
    anon.highFivesGuys();
    fidson.guardGate();
    return 0;
}
