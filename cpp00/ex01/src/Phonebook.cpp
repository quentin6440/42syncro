/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:13 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 15:06:52 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
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

	printField("slot");
	printField("First name");
	printField("Last name");
	printField("Nickname");
	std::cout << "|\n";

	while (i < ct)
	{
		std::cout << "|" << std::setw(10) << i;
		printField(contacts[i].getName());
		printField(contacts[i].getSurname());
		printField(contacts[i].getNickname());
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
	std::cout <<"tab here \n";
	displayTab();
	std::cout << "Capacity of memory 8 total , current count :" << ct << "\n search what index? : ";
	if (!readline(s))
		return ;
	if (!ft_isnum(s))
	{
		std::cout << "\n mollo l'andouille\n";
		return ;
	}
	i = std::atoi(s.c_str());
	if (i >= 8)
	{
		std::cout << "\n over the capacity mate\n";
		return ;
	}
	if (i >= ct)
	{
		std::cout << "\n not registered\n";
		return ;
	}
	std::cout <<"\ndisplay info here \n";
	contacts[i].displayInfo();
	std::cout << "\nfinish\n";
}
