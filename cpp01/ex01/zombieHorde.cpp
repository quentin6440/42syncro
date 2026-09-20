#include "Zombie.h"
#include <string>

Zombie  *newZombie(std::string name)
{    
        return new Zombie(name);
}

Zombie *zombies = new Zombie[5];