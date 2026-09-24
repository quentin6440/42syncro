#include "Zombie.h"

int main()
{
	Zombie	*myzombie = newZombie("Jack");

	myzombie->announce();

	randomChump("Charlie");

	delete myzombie;

    return 0;
}