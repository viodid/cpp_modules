#include "Harl.hpp"

#include <iterator>


Harl::Harl(void)
{
	_complain_ptr[hash_map("DEBUG")] = &debug;
	_complain_ptr[hash_map("INFO")] = &debug;
	_complain_ptr[hash_map("WARNING")] = &debug;
	_complain_ptr[hash_map("ERROR")] = &debug;
}

void Harl::complain(std::string level)
{
	void (Harl::*complain_ptr) () = &debug;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << " think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int hash_map(const std::string& value)
{
	return (1);
}
