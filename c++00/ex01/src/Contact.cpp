/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:59 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 17:32:39 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

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
	std::cout << "\n";
	printFormatted(15, "First name");
	std::cout << " : ";
	printFormattedL(30, name);
	std::cout << "\n";
	printFormatted(15, "Last name");
	std::cout << " : ";
	printFormattedL(30, surname);
	std::cout << "\n";
	printFormatted(15, "Nick name");
	std::cout << " : ";
	printFormattedL(30, nickname);
	std::cout << "\n";
	printFormatted(15, "Phone number");
	std::cout << " : ";
	printFormattedL(30, phoneNumber);
	std::cout << "\n";
	printFormatted(15, "Darkest Secret");
	std::cout << " : ";
	printFormattedL(30, secret);
	std::cout << "\n";
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
