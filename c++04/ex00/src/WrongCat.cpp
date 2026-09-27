#include "../inc/WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other) {
    // Copy constructor implementation
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    // Assignment operator implementation
    std::cout << "WrongCat assignment operator called" << std::endl;

    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    // Destructor implementation
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    // Default sound implementation
    std::cout << "MEOW MEOW" << std::endl;
}