#include "Harl.hpp"

#include <iterator>
#include <iterator>

void Harld::complain(std::string level)
{
	void (Harld::*complain_ptr) () = &debug;
}

void Harld::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harld::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harld::warning()
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harld::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}




