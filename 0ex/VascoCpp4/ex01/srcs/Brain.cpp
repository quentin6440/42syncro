
#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain Constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain Copy Constructor called." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < BRAIN_SIZE; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called." << std::endl;
}

void Brain::setIdea(const std::string& idea, int index) {
	if (index >= 0 && index < BRAIN_SIZE)
		ideas[index] = idea;
}

const std::string& Brain::getIdea(int index) const {
	static const std::string empty = "";

	if (index >= 0 && index < BRAIN_SIZE)
		return ideas[index];
	return empty;
}
