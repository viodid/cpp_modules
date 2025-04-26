#include "../include/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& obj)
{
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = obj.getIdeas()[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
    std::cout << "Brain copy assignment operator called." << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = obj.getIdeas()[i];
    return *this;
}

const std::string* Brain::getIdeas() const
{
    return _ideas;
}
