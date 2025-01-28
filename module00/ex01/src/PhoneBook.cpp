/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:26 by dyunta            #+#    #+#             */
/*   Updated: 2025/01/07 17:03:07 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../include/PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _index(0)
{
}

std::string PhoneBook::get_input(const std::string& msg)
{
	std::string output;

	std::cout << msg;
	std::cin >> output;
	return (output);
}

void PhoneBook::add_contact()
{
	Contact *contact = &_phone_book[_index];
	contact->set_first_name(get_input("First name: "));
	contact->set_last_name(get_input("Last name: "));
	contact->set_nick_name(get_input("Nick name: "));
	contact->set_phone_number(get_input("Phone number: "));
	contact->set_darkest_secret(get_input("Darkest secret: "));
	_index++;
	_index %= 8;
}

void PhoneBook::display_contacts(const PhoneBook& phone_book) const
{
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		Contact contact = phone_book._phone_book[i];
		if (contact.get_first_name().empty())
			break;
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << truncate_str(contact.get_first_name()) << " | ";
		std::cout << std::setw(10) << truncate_str(contact.get_last_name()) << " | ";
		std::cout << std::setw(10) << truncate_str(contact.get_nick_name()) << std::endl;
	}
}

void PhoneBook::display_single_contact(const int i) const
{
	_phone_book[i].display_contact();
}

std::string PhoneBook::truncate_str(const std::string& str)
{
	if (str.length() <= 10)
		return str;
	return (str.substr(8) + ".");
}
