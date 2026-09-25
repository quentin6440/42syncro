
#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): type("") {
	std::cout << "AAnimal Constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal Copy Constructor called." << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor called." << std::endl;
}

const std::string& AAnimal::getType() const {
	return type;
}

void AAnimal::setType(const std::string& newType) {
	type = newType;
}
