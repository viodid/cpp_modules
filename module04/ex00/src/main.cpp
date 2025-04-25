#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal animal = *meta;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal.makeSound();
    delete meta;
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
