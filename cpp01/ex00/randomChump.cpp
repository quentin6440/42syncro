#include "Zombie.h"
#include <string>

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}