/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:26 by dyunta            #+#    #+#             */
/*   Updated: 2025/01/07 17:03:07 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Contact.hpp"

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}

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

void	Contact::set_first_name(const std::string& fn)
{
	_first_name = fn;
}

void	Contact::set_last_name(const std::string& ln)
{
	_first_name = ln;
}

void	Contact::set_nick_name(const std::string& nn)
{
	_first_name = nn;
}

void	Contact::set_phone_number(const std::string& pn)
{
	_first_name = pn;
}

void	Contact::set_darkest_secret(const std::string& ds)
{
	_first_name = ds;
}

void Contact::display_contact() const
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nick name: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

