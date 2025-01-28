#ifndef PHONEBOOK_H
#define PHONEBOOK_H


# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();

	void add_contact();
	static std::string get_input(const std::string& msg);
	void display_contacts() const;
	void display_single_contact(int i) const;

private:
	Contact _phone_book[8];
	int _index;

	static std::string truncate_str(const std::string& str);
};

#endif
