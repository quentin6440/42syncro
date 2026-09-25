
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
	std::cout << "Cat Constructor called." << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat& other): Animal(other) {
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meoowww!" << std::endl;
}
