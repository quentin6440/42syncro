/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:59 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 14:44:12 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>

bool Contact::setInfo()
{
	std::cout << "First name :\n";
	if (!readline(this->name))
		return 0;

	std::cout << "Last name :\n";
	if (!readline(this->surname))
		return 0;

	std::cout << "Nick name :\n";
	if (!readline(this->nickname))
		return 0;

	std::cout << "Phone number :\n";
	if (!readline(this->phoneNumber))
		return 0;
	if (phoneNumber != "") {
		while (!ft_isnum(this->phoneNumber))
		{
			std::cout << "Phone number must contain only digits, retry :\n";
			if (!readline(this->phoneNumber))
				return 0;
		}
	}

	std::cout << "Darkest secret :\n";
	if (!readline(this->secret))
		return 0;

	return 1;
}

void Contact::displayInfo()
{
	printField("First name");
	printField("Last name");
	printField("Nickname");
	printField("Phone number");
	printField("Darkest secret");
	std::cout << "|\n";

	printField(name);
	printField(surname);
	printField(nickname);
	printField(phoneNumber);
	printField(secret);
	std::cout << "|\n";
}

std::string	Contact::getName() {
	return this->name;
}
std::string	Contact::getSurname() {
	return this->surname;
}
std::string	Contact::getNickname() {
	return this->nickname;
}
