#include "../include/Weapon.h"

#include <string>

        Weapon::Weapon(const std::string& type) : _type(type)
{

}

void    Weapon::setType(const std::string& type)
{
    this->_type = type;
}

const std::string& Weapon::getType(void) const
{
    return (this->_type);
}
