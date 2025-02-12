#include "../include/ClapTrap.hpp"

int main() {

	ClapTrap anon("anon");
	anon.attack("someone");
	anon.beRepaired(3);
	anon.takeDamage(12);
	anon.attack("another one");
	anon.takeDamage(1);
	anon.beRepaired(10);
	return 0;
}
