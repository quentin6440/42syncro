#include "../inc/Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) 
    : Animal(other), _brain(new Brain(*other._brain)) {
    // Copy constructor implementation
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
    // Assignment operator implementation
    std::cout << "Dog assignment operator called" << std::endl;

    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;    
    }
    return *this;
}

Dog::~Dog() {
    // Destructor implementation
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    // Default sound implementation
    std::cout << "WOOF WOOF" << std::endl;
}

void Dog::setIdea(int index, std::string const &idea)
{
    _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return _brain->getIdea(index);
}