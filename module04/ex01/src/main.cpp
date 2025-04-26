#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

#define ARR_LEN 4

int main()
{
    const Animal* arr[ARR_LEN];
    for (int i = 0; i < ARR_LEN / 2; i++)
        arr[i] = new Dog;
    for (int i = ARR_LEN / 2; i < ARR_LEN; i++)
        arr[i] = new Cat;
    for (int i = 0; i < ARR_LEN; i++) {
        arr[i]->makeSound();
        delete arr[i];
    }

    std::cout << "------" << std::endl;

    Dog basic;
    std::cout << "basic:\t\t" << basic.getBrain() << std::endl;
    {
        Dog tmp = basic;
        std::cout << "tmp:\t\t" << tmp.getBrain() << std::endl;
    }

    return (0);
}
