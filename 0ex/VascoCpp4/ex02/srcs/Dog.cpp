
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): AAnimal(), brain(new Brain()) {
	std::cout << "Dog Constructor called." << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& other): AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called." << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}

Brain& Dog::getBrain() {
	return *brain;
}

const Brain& Dog::getBrain() const {
	return *brain;
}
