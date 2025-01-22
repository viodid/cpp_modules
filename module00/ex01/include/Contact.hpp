#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

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
