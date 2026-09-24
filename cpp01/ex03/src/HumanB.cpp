#include "../include/HumanB.h"
#include "../include/Weapon.h"
#include <iostream>

HumanB::HumanB(const std::string& name) 
    : _name(name)
{
}

void    HumanB::setWeapon(Weapon& type)
{
    this->_weapon = &type;
}

void HumanB::attack(void) const
{
    std::cout   << this->_name 
                << " attacks with their " 
                << this->_weapon->getType() 
                << std::endl;
}
