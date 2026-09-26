#include "../inc/ScavTrap.hpp"

#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called for the object named: " << this->_name << std::endl;
    this->_name = "Default ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) 
    : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called for the object named: " << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for the object named: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name) {
    std::cout << "ScavTrap custom constructor called for the object named: " << this->_name << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target 
                  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->_name << " cannot attack, ran out of energy or hit points." << std::endl;
    }
}