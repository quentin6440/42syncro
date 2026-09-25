
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): AAnimal(), brain(new Brain()) {
	std::cout << "Cat Constructor called." << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat& other): AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called." << std::endl;
	delete brain;
}

/*void Cat::makeSound() const {
	std::cout << "Meoowww!" << std::endl;
}*/

Brain& Cat::getBrain() {
	return *brain;
}

const Brain& Cat::getBrain() const {
	return *brain;
}
