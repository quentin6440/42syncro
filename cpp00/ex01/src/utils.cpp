/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:35:18 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 14:42:59 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iomanip>
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

std::string	formatField(const std::string &str) {
	int	len = str.length();
	if (len <= 10)
		return str;

	return str.substr(0, 9) + ".";
}

void	printField(const std::string &str) {
	std::cout	<< "|" 
					<< std::setw(10) 
					<< formatField(str);
}

bool    readline(std::string &str) {

	if (!std::getline(std::cin , str))
	{
		std::cout << "no entry" << std::endl;
		return 0;
	}
	return 1;
}