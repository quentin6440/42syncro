#include "../inc/ClapTrap.hpp"

#include <iostream>

int main()
{
    std::cout << "===== CONSTRUCTORS =====" << std::endl;

    ClapTrap clap1("ClappyBoy");
    ClapTrap clap2(clap1);
    ClapTrap clap3;

    clap3 = clap1;

    std::cout << "\n===== ATTACK =====" << std::endl;

    clap1.attack("Target");
    clap1.attack("Target");

    std::cout << "\n===== TAKE DAMAGE =====" << std::endl;

    clap1.takeDamage(5);
    clap1.takeDamage(10);

    std::cout << "\n===== REPAIR =====" << std::endl;

    clap2.beRepaired(5);
    clap2.beRepaired(5);

    std::cout << "\n===== ENERGY TEST =====" << std::endl;

    ClapTrap clap4("Henri");

    for (int i = 0; i < 3; i++)
        clap4.attack("Target");

    std::cout << "\n===== DESTRUCTORS =====" << std::endl;

    return 0;
}
