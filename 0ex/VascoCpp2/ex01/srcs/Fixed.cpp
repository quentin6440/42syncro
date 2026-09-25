
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	rawBits = other.rawBits;
}

Fixed::Fixed(const int value) {
	rawBits = value * (1 << fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	rawBits = roundf(value * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

int Fixed::toInt( void ) const {
	return rawBits >> fractionalBits;
}

float Fixed::toFloat( void ) const {
	return (float)rawBits / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
