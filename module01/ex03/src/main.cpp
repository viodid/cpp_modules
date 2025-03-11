#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"
#include "../include/Weapon.hpp"


int main(void)
{
	Weapon weaponA("crude spiked club");
	HumanA bob(weaponA, "Bob");
	bob.attack();
	weaponA.setType("some other type of club");
	bob.attack();

	Weapon weaponB("crude spiked club");
	HumanB alice("Alice");
	alice.setWeapon(NULL);
	alice.attack();
	weaponB.setType("some other type of club");
	alice.attack();

	return (0);
}
