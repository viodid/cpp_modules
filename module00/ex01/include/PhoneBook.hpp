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
	void	search_contact(int	contact_id)
	{

	}
private:
	void	print_contact(Contact contact)
	{
		std::cout << "wip";
	}
};

#endif
