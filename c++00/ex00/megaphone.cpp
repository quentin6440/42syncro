/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcyril-a <qcyril-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 14:34:15 by qcyril-a          #+#    #+#             */
/*   Updated: 2026/09/08 14:41:09 by qcyril-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char *av[])
{
	int    i = 0;
	int    j = 0;

	if (ac < 2)
	std::cout   << "*LOUD AND UNBEARABLE FEEDBACK NOISE*";
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			std::cout   << static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(av[i][j++])));
		}
	}
	std::cout << std::endl;
	return 0;
}