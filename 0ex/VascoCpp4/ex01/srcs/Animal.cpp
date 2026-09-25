
#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("") {
	std::cout << "Animal Constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal Copy Constructor called." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called." << std::endl;
}

const std::string& Animal::getType() const {
	return type;
}

void Animal::setType(const std::string& newType) {
	type = newType;
}

void Animal::makeSound() const {
	std::cout << "..." << std::endl;
}
