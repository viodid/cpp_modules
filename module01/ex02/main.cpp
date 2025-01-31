#include <string>
#include <iostream>

int main(void)
{
	const std::string zombie = "HI THIS IS BRAIN";
	const std::string* stringPTR = &zombie;
	const std::string& stringREF = zombie;

	std::cout << "memory address zombie:\t\t" << &zombie << std::endl;
	std::cout << "memory address stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory address stringREF:\t" << &stringREF << std::endl;

	std::cout << "value of zombie:\t\t" << zombie << std::endl;
	std::cout << "value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF:\t" << stringREF << std::endl;
	return (0);
}
