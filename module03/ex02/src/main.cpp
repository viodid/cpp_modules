#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap fidson("fidson");
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
