#include <Brain.hpp>

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
}
