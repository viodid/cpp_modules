#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook() {delete phone_book;}
	void	add_contact(Contact contact);
	void	search_contact(const int	contact_id)
	{
		if (contact_id > 8 || contact_id < 1)
		{
			std::cout << "Index contact cannot be > 8 or < 1";
			return;
		}
		Contact *contact = phone_book[contact_id];
		print_contact(contact->first_name);
	}
private:
	Contact	_phone_book[8];
	int		_index = 0;
};

#endif
