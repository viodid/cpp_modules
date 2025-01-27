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
	Contact contact = _phone_book[_index];
	contact.set_first_name(get_input("First name: "));
	contact.set_last_name(get_input("Last name: "));
	contact.set_nick_name(get_input("Nick name: "));
	contact.set_phone_number(get_input("Phone number: "));
	contact.set_darkest_secret(get_input("Darkest secret: "));
	_index++;
	_index %= 8;
}
