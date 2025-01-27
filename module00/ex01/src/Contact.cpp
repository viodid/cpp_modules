# include "../include/Contact.hpp"


Contact::Contact(
	std::string const& fn,
	std::string const& ln,
	std::string const& nn,
	std::string const& pn,
	std::string const& ds
) :
	_first_name(fn),
	_last_name(ln),
	_nickname(nn),
	_phone_number(pn),
	_darkest_secret(ds)
{
}

std::string Contact::get_first_name()
{
	return _first_name;
}

std::string Contact::get_last_name()
{
	return _last_name;
}

std::string Contact::get_nick_name()
{
	return _nickname;
}

std::string Contact::get_phone_number()
{
	return _phone_number;
}

std::string Contact::get_darkest_secret()
{
	return _darkest_secret;
}

