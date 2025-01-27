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

void	PhoneBook::add_contact(Contact contact)
{
	_phone_book[_index] = std::move(contact);
}
