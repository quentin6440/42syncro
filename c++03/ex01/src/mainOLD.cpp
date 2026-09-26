#include "../inc/ScavTrap.hpp"

#include <iostream>

int main()
{
/*    ScavTrap x;
    ScavTrap y(x);
    ScavTrap z;
    z = y;

    ScavTrap m("M. ScavY");
*/
    {
        std::cout << "===== ScavTrap creation =====" << std::endl;

        ScavTrap x("Serena");

        std::cout << "\n===== ScavTrap actions =====" << std::endl;

        x.attack("Target Dummy");
        x.takeDamage(30);
        x.beRepaired(20);
        x.guardGate();

        std::cout << "\n===== Destruction =====" << std::endl;

    }
    
    return 0;
}
