#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#define ARR_LEN 4

int main()
{
    const AAnimal* arr[ARR_LEN];
    for (int i = 0; i < ARR_LEN / 2; i++)
        arr[i] = new Dog;
    for (int i = ARR_LEN / 2; i < ARR_LEN; i++)
        arr[i] = new Cat;
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i]->makeSound();
        delete arr[i];
    }

    const Dog dog;
    const Dog copyDog(dog);
    std::cout << "dog:\t\t" << dog.getBrain() << std::endl;
    std::cout << "copyDog:\t" << copyDog.getBrain() << std::endl;

    // const AAnimal animal; // you cannot instantiate an abstract class

    return (0);
}
