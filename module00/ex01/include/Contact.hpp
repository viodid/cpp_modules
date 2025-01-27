#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
	Contact(
		std::string const& fn,
		std::string const& ln,
		std::string const& nn,
		std::string const& pn,
		std::string const& ds
		);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	std::string get_phone_number();
	std::string get_darkest_secret();
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif
