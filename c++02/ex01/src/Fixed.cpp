#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fxpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fxpValue(value * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fxpValue(roundf(value * (1 << _fractionalBits)))
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

std::ostream &operator<<(std::ostream &ostrm, Fixed const &nbr)
{
	return (ostrm << nbr.toFloat());
}
