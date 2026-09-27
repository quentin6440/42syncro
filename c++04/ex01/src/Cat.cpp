#include "../inc/Cat.hpp"

#include <iostream>

Cat::Cat() 
    : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) 
    : Animal(other), _brain(new Brain(*other._brain)) {
    // Copy constructor implementation
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
    // Assignment operator implementation
    std::cout << "Cat assignment operator called" << std::endl;

    if (this != &other) {
        Animal::operator=(other);    
        *_brain = *other._brain;
    }
    return *this;
}

Cat::~Cat() {
    // Destructor implementation
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    // Default sound implementation
    std::cout << "MEOW MEOW" << std::endl;
}

void Cat::setIdea(int index, std::string const &idea)
{
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return _brain->getIdea(index);
}