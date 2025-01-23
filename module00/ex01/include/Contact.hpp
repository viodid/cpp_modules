#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	Contact(
		std::string fn,
		std::string ln,
		std::string nn,
		std::string pn,
		std::string ds
	)
	{
		first_name = fn;
		last_name = ln;
		nickname = nn;
		phone_number = pn;
		darkest_secret = ds;
	}
};

#endif
