#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	**phone_book = new Contact*;
	int		m_size = 0;
public:
	~PhoneBook() {delete phone_book;}
	void	add_contact(Contact *contact) const {phone_book[m_size] = contact;}
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
	void	print_contact(std::string str)
	{
		std::cout << contact->first_name << '\n';
		std::cout << contact->last_name << '\n';
	}
};

#endif
