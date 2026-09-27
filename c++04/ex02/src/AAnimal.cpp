#include "../inc/AAnimal.hpp"

#include <iostream>
#include <string>

AAnimal::AAnimal() : _type("*unspecified animal*") {
    // Constructor implementation
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) : _type(other._type) {
    // Copy constructor implementation
    std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
    // Assignment operator implementation
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    // Destructor implementation
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
    // Constructor implementation
    std::cout << "Animal typed constructor called" << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
}