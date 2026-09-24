#include "Zombie.h"
#include <string>

Zombie  *newZombie(std::string name)
{
    return new Zombie(name);
}