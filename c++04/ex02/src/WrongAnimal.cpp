#include "../inc/WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : _type("*unspecified animal*") {
    // Constructor implementation
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type) {
    // Copy constructor implementation
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    // Assignment operator implementation
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    // Destructor implementation
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    // Constructor implementation
    std::cout << "WrongAnimal typed constructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    // Default sound implementation
    std::cout << "*GNEGNEGNE* (Generic WrongAnimal Sound)" << std::endl;
}