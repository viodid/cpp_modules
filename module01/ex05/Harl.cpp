#include "Harl.hpp"

#include <iterator>


Harl::Harl(void)
{
	_complain_ptr[hash("DEBUG")] = &Harl::debug;
	_complain_ptr[hash("INFO")] = &Harl::info;
	_complain_ptr[hash("WARNING")] = &Harl::warning;
	_complain_ptr[hash("ERROR")] = &Harl::error;
}

Harl::~Harl() { }


void Harl::complain(std::string level) { (this->*_complain_ptr[hash(level)])(); }

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info()
{
	std::cout <<
		"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning()
{
	std::cout <<
		"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


int Harl::hash(const std::string& value)
{
	int arr_index = 0;
	for (unsigned int i = 0; i < value.length(); i++)
		arr_index += value[i];
	arr_index %= 8;
	return (arr_index);
}
