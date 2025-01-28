/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:26 by dyunta            #+#    #+#             */
/*   Updated: 2025/01/07 17:03:07 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "../include/PhoneBook.hpp"

int main()
{
	PhoneBook phone_book;
	std::string cmd;

	while (!std::cin.eof())
	{
		std::cout << "Enter command [ADD, SEARCH, EXIT]: ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD")
		{
			phone_book.add_contact();
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else if (cmd == "SEARCH")
		{
			std::string buffer;
			phone_book.display_contacts(phone_book);
			std::cout << "Index to display: ";
			std::cin >> buffer;
			const int index = atoi(buffer.c_str());
			if (index < 1 || index > 8)
				std::cout << "Index out of range 1 - 8";
			else
				phone_book.display_single_contact(index);
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else if (cmd == "EXIT")
			break;
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}
