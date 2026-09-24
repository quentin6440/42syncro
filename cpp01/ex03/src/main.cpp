
#include "../include/HumanA.h"
#include "../include/HumanB.h"
#include <iostream>
/*
int main(void)
{
    std::cout << "This is ' Unnecessary Violence '\n\n";

    {
//        Weapon  club1 = new Weapon("crude spiked club");
        Weapon  weapon1("crude spiked club");

        HumanA fighter1("bob", weapon1);

        fighter1.attack();

        weapon1.setType("tennis racket");
        fighter1.attack();
//      delete club1;

    }
    return 0;
}*/
int main(void)
{
    std::cout << "This is ' Unnecessary Violence '\n\n";

{
Weapon  club = Weapon("crude spiked club");
HumanA  hA1("Bob", club);
hA1.attack();
club.setType("some other type of club");
hA1.attack();
}
{
Weapon  club1 = Weapon("crude spiked club");
HumanB  hB1("Jim");
hB1.setWeapon(club1);
hB1.attack();
club1.setType("some other type of club");
hB1.attack();
}
    return 0;
}
