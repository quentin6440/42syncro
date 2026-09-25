/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 00:54:18 by smarques          #+#    #+#             */
/*   Updated: 2026/09/06 00:54:18 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fpValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->fpValue = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fpValue = raw;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->fpValue = nbr << this->bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpValue = roundf( nbr * (1 << this->bits));
}

int	Fixed::toInt() const
{
	return (this->fpValue >> this->bits);
}

float	Fixed::toFloat() const
{
	return (float(this->fpValue) / (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostrm, Fixed const &nbr)
{
	return (ostrm << nbr.toFloat());
}

bool	Fixed::operator>(Fixed const &other) const
{
	if (this->fpValue > other.fpValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(Fixed const &other) const
{
	if (this->fpValue < other.fpValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	if (this->fpValue >= other.fpValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	if (this->fpValue <= other.fpValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const &other) const
{
	if (this->fpValue == other.fpValue)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	if (this->fpValue != other.fpValue)
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	Fixed	result(*this);

	result.fpValue += other.fpValue;
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result(*this);

	result.fpValue -= other.fpValue;
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	result(*this);

	result.fpValue = (static_cast<int64_t>(result.fpValue) * other.fpValue) / (1 << this->bits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	result(*this);

	result.fpValue = (int64_t(result.fpValue) * (1 << this->bits)) / other.fpValue;
	return (result);
}

Fixed	&Fixed::operator++()
{
	this->fpValue = this->fpValue + 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fpValue = this->fpValue + 1;
	return(tmp);
}

Fixed	&Fixed::operator--()
{
	this->fpValue = this->fpValue - 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fpValue = this->fpValue - 1;
	return(tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first < second)
		return (first);
	else
		return (second);

}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}