#include "Zombie.h"
#include <iostream>

Zombie::Zombie() : _name("unnamed zombie") {
    std::cout << "'" << _name << "' - constructor called\n";
	return;
}

Zombie::~Zombie()
{
    std::cout << "'" << _name << "' - destructor called\n";
    return;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
