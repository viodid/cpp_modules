#ifndef HARL_H
#define HARL_H
#include <string>
#include <iostream>

class Harl
{
public:
	Harl();
	void complain(std::string level);

private:
	void (Harl::*_complain_ptr[4])();
    int hash(const std::string& value);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
