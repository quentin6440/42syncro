#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fxpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) 
	: _fxpValue(value * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) 
	: _fxpValue(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_fxpValue = src._fxpValue;
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fxpValue;
}

void Fixed::setRawBits(const int raw)
{
	this->_fxpValue = raw;
}

int	Fixed::toInt() const
{
	return (this->_fxpValue >> this->_fractionalBits);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->_fxpValue) / (1 << _fractionalBits));
}

//Comparisons

bool	Fixed::operator>(const Fixed &other) const
{
	return this->_fxpValue > other._fxpValue;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->_fxpValue < other._fxpValue;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->_fxpValue >= other._fxpValue;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->_fxpValue <= other._fxpValue;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->_fxpValue == other._fxpValue;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->_fxpValue != other._fxpValue;
}

//Arithmetic operations

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result._fxpValue = this->_fxpValue + other._fxpValue;
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result._fxpValue = this->_fxpValue - other._fxpValue;
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result._fxpValue = static_cast<int>(
		(static_cast<long long>(this->_fxpValue)
		* static_cast<long long>(other._fxpValue))
		>> this->_fractionalBits
	);

	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result._fxpValue = static_cast<int>(
		(static_cast<long long>(this->_fxpValue)
		<< this->_fractionalBits)
		/ other._fxpValue
	);

	return result;
}

//increment & decrement

Fixed	&Fixed::operator++()
{
	++this->_fxpValue;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed old(*this);

	++this->_fxpValue;
	return old;
}

Fixed	&Fixed::operator--()
{
	--this->_fxpValue;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed old(*this);

	--this->_fxpValue;
	return old;
}

//min & max

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

//Display operator

std::ostream &operator<<(std::ostream &ostrm, Fixed const &nbr)
{
	return (ostrm << nbr.toFloat());
}
