/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:18 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 17:41:17 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

bool	ft_isnum(const std::string &s) {

	int i = 0;
	int	len = s.length();
	if (len == 0)
		return 0;
	while (i < len)
	{
		if (s[i] < 48 || s[i] > 57)
			return 0;
		i++;
	}
	return 1;
}

std::string	formatField(int i, const std::string &str) {
	int	len = str.length();
	if (len <= i)
		return str;
	return str.substr(0, i - 1) + ".";
}

void	printField(int i,const std::string &str) {
	std::cout	<< "|" 
					<< std::setw(i) 
					<< formatField(i, str);
}

void	printFormatted(int i,const std::string &str) {
	std::cout	<< std::right 
				<< std::setw(i)
				<< formatField(i, str);
}

void	printFormattedL(int i,const std::string &str) {
	std::cout	<< std::left 
				<< std::setw(i)
				<< formatField(i, str);
}

bool    readline(std::string &str) {

	if (!std::getline(std::cin , str))
	{
		std::cout << "no entry" << std::endl;
		return 0;
	}
	return 1;
}