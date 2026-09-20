#include "Zombie.h"
#include <iostream>
#include <unistd.h>

int main()
{
    std::cout << "HEllo\n";

	struct Zombie zombie1("Joe");
	zombie1.announce();

	Zombie	*zombie2 = newZombie("Jack");
	zombie2->announce();
	delete zombie2;

	randomChump("Charlie");

    return 0;
}