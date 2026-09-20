#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
    std::cout << "Zombie constructor\n";

    return;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destructor\n";
    return;
}

void    Zombie::announce(void)
{
    std::cout << "Brain !\n";
}