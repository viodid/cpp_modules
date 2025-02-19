#include <algorithm>
#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>

# define ARR_LEN 10

int main()
{
	const Dog basic;
    const Dog tmp = basic;
	std::cout << "basic: " << &basic << std::endl;
	std::cout << "tmp: " << &tmp << std::endl;


	// Animal *arr = new Animal[ARR_LEN];
	// for (int i = 0; i < ARR_LEN / 2; i++)
	// 	arr[i] = Dog();
	// for (int i = ARR_LEN / 2; i < ARR_LEN; i++)
	// 	arr[i] = Cat();
 //    delete [] arr;
	return (0);
}
