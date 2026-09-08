/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:13 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 17:36:34 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstdio>


Phonebook::Phonebook() 
{
	index = 0;
	ct = 0;
}

void    Phonebook::addContact(){
	std::size_t	slot = index % 8;
	std::cout << "add :\n";
	if (!contacts[slot].setInfo())
		return ;
	std::cout << "contact created successfully, located at slot num : " << slot << "\n";
	index++;
	if (ct < 8)
		ct++;
}

void Phonebook::displayTab()
{
	std::size_t i = 0;

	printField(10, "slot");
	printField(10, "First name");
	printField(10, "Last name");
	printField(10, "Nickname");
	std::cout << "|\n";

	while (i < ct)
	{
		std::cout << "|" << std::setw(10) << i;
		printField(10, contacts[i].getName());
		printField(10, contacts[i].getSurname());
		printField(10, contacts[i].getNickname());
		std::cout << "|\n";

		i++;
	}
}


void    Phonebook::searchContact()
{
	std::size_t i = 0;
	std::string s; 

	if (ct == 0)
	{
		std::cout << "enter at least one contact with add\n";
		return ;
	}
	displayTab();
	std::cout << "Capacity of memory : 8 ; current count : " << ct << "\n Explore which index? : ";
	if (!readline(s))
		return ;
	if (!ft_isnum(s) || i >= 8)
	{
		std::cout << "\n Bad usage\n";
		return ;
	}
	if (i >= ct)
	{
		std::cout << "\n Not registered\n";
		return ;
	}
	contacts[i].displayInfo();
	std::cout << "\n----------------\n";
}
