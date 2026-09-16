#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
    std::cout << "Zombie constructor\n";
    return;
}

Zombie::~Zombie()
{
    std::cout << "Zombie destructor";
    return;
}

void    Zombie::announce(void)
{
    std::cout << "hello im a brain? !\n";
}