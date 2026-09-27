#include "../inc/Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal() : _type("*unspecified animal*") {
    // Constructor implementation
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type) {
    // Copy constructor implementation
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
    // Assignment operator implementation
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

Animal::~Animal() {
    // Destructor implementation
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    // Constructor implementation
    std::cout << "Animal typed constructor called" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    // Default sound implementation
    std::cout << "*GNEGNEGNE* (Generic Animal Sound)" << std::endl;
}