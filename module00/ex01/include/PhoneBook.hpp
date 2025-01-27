#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();

	void add_contact();
	static std::string get_input(const std::string& msg);

private:
	Contact _phone_book[8];
	int _index;
};

#endif
