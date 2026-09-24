
#include "../include/HumanA.h"
#include "../include/HumanB.h"

/*
int main(void)
{
    std::cout << "This is ' Unnecessary Violence '\n\n";

    {
        //Weapon  *weapon1 = new Weapon("crude spiked club");
        Weapon  weapon1("crude spiked club");

        HumanA fighter1("bob", weapon1);

        fighter1.attack();

        weapon1.setType("tennis racket");
        fighter1.attack();
        //delete weapon1;

    }
    return 0;
}*/

int main()
{
{
    Weapon  club = Weapon("crude spiked club");
    HumanA  bob("Bob", club);

    bob.attack();
    club.setType("some other type of club");
    bob.attack();
}
{
    HumanB  jim("Jim");
    Weapon  club = Weapon("crude spiked club");
    
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
}
	return 0;
}
