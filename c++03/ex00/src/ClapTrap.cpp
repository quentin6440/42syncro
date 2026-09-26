#include "../inc/ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() 
    : _name("*unnamed*"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for object named: " << (*this)._name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called for object named: " << this->_name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assignment operator called for the object named: " << this->_name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for the object named: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap custom constructor called for the object named: " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } else {
        std::cout << "ClapTrap " << _name << " cannot attack, ran out of energy or hit points." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        if (_hitPoints < 0) _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
    }
    if (_hitPoints == 0 && amount) {
        std::cout << " ... ClapTrap " << _name << " has died." << std::endl;
    } else {
        std::cout <<  std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount 
                  << " points! Remaining hit points: " << _hitPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " cannot be repaired due to insufficient hit points or energy." << std::endl;
    }
}