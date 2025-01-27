#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
public:
	Contact();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	std::string get_phone_number();
	std::string get_darkest_secret();
	void set_first_name(const std::string& fn);
	void set_last_name(const std::string& ln);
	void set_nick_name(const std::string& nn);
	void set_phone_number(const std::string& pn);
	void set_darkest_secret(const std::string& ds);
	void display_contact() const;
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif
