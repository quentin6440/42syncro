
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("") {
	std::cout << "WrongAnimal Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal Copy Constructor called." << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called." << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::setType(const std::string& newType) {
	type = newType;
}

void WrongAnimal::makeSound() const {
	std::cout << "..." << std::endl;
}
