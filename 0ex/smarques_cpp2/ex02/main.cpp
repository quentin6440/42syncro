/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:54:30 by smarques          #+#    #+#             */
/*   Updated: 2026/09/06 00:54:30 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed nbr1(4000000);
	Fixed nbr2(2);

	int int_nbr1 = 4000000;
	int int_nbr2 = 2;

	std::cout << nbr1 * nbr2 << std::endl;
	std::cout << int_nbr1 * int_nbr2 << std::endl;



	Fixed c(5);
	Fixed d(2.5f);
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << c / d << std::endl;

	if (c > d)
		std::cout << "c is bigger" << std::endl;
	if (d < c)
		std::cout << "d is smaller" << std::endl;

	if (c != d)
		std::cout << "c and d are different" << std::endl;

	Fixed e = Fixed::min(c, d);
	std::cout << e << std::endl;



	Fixed smallest_nbr;
	std::cout << smallest_nbr << std::endl;
	smallest_nbr++;
	std::cout << smallest_nbr << std::endl;

	return (0);
}