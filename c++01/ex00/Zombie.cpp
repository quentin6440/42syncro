#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "'" << _name << "' - constructor called\n";
    return;
}

Zombie::~Zombie()
{
    std::cout << "'" << _name << "' - destructor called\n";
    return;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}