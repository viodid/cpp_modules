#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	const Animal* pre_animal = new Animal();
	const Animal animal = *pre_animal;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal.makeSound();
	delete pre_animal;
	delete dog;
	delete cat;

	std::cout << "---" << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	return (0);
}
