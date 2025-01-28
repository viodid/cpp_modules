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
			phone_book.add_contact();
		else if (cmd == "SEARCH")
		{
			phone_book.display_contacts();
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
