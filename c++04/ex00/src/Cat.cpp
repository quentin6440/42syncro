#include "../inc/Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
    // Copy constructor implementation
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
    // Assignment operator implementation
    std::cout << "Cat assignment operator called" << std::endl;

    if (this != &other) {
        Animal::operator=(other);    }
    return *this;
}

Cat::~Cat() {
    // Destructor implementation
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    // Default sound implementation
    std::cout << "MEOW MEOW" << std::endl;
}