#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
#include <string>

class Brain
{
public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	Brain& operator=(const Brain& obj);
private:
	std::string _ideas[100];
};

#endif
