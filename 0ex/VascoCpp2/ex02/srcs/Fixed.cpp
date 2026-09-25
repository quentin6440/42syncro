
#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <stdint.h>

Fixed::Fixed(): rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
	rawBits = other.rawBits;
}

Fixed::Fixed(const int value) {
	rawBits = value * (1 << fractionalBits);
}

Fixed::Fixed(const float value) {
	rawBits = roundf(value * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

bool Fixed::operator>(const Fixed& other) const {
	return (rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed& other) const {
	return (rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (rawBits <= other.rawBits);
}

bool Fixed::operator==(const Fixed& other) const {
	return (rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (rawBits != other.rawBits);
}

Fixed Fixed::operator+(const Fixed& other) const {
	// return Fixed(toFloat() + other.toFloat());
	Fixed r;
	r.rawBits = (rawBits + other.rawBits);
	return r;
}

Fixed Fixed::operator-(const Fixed& other) const {
	// return Fixed(toFloat() - other.toFloat());
	Fixed r;
	r.rawBits = (rawBits - other.rawBits);
	return r;
}

Fixed Fixed::operator*(const Fixed& other) const {
	// return Fixed(toFloat() * other.toFloat());
	Fixed r;
	r.rawBits = (static_cast<int64_t>(rawBits) * other.rawBits) >> fractionalBits;
	return r;
}

Fixed Fixed::operator/(const Fixed& other) const {
	// return Fixed(toFloat() / other.toFloat());
	Fixed r;
	r.rawBits = ((static_cast<int64_t>(rawBits) * (1 << fractionalBits)) / other.rawBits);
	return r;
}

Fixed& Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	rawBits++;
	return temp;
}

Fixed& Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	rawBits--;
	return temp;
}

int Fixed::getRawBits(void) const {
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

int Fixed::toInt(void) const {
	return rawBits >> fractionalBits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(rawBits) / (1 << fractionalBits);
}

static Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

static const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

static Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

static const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
