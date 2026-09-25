
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Dog Constructor called." << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}
