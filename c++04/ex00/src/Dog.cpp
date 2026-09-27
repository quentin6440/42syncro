#include "../inc/Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other) {
    // Copy constructor implementation
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
    // Assignment operator implementation
    std::cout << "Dog assignment operator called" << std::endl;

    if (this != &other) {
        Animal::operator=(other);    }
    return *this;
}

Dog::~Dog() {
    // Destructor implementation
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    // Default sound implementation
    std::cout << "WOOF WOOF" << std::endl;
}