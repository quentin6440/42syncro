
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "WrongCat Constructor called." << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meoowww!" << std::endl;
}
