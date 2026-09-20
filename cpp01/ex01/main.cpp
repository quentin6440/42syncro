#include "Zombie.h"
#include <iostream>
#include <unistd.h>

int main()
{
	Zombie *zombies = new Zombie[5];

Zombie *horde = zombieHorde(5, "Bob");

for (int i = 0; i < 5; i++)
    horde[i].announce();

delete[] horde;

    return 0;
}