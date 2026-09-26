#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "========== ClapTrap test ==========" << std::endl;

	ClapTrap clap("Clappy");

	clap.attack("an enemy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << std::endl;

	std::cout << "========== ScavTrap test ==========" << std::endl;

	ScavTrap scav("Guardian");

	scav.attack("a powerful enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << std::endl;

    std::cout << "========== Energy test ==========" << std::endl;

    ScavTrap tired("Tired");

    for (int i = 0; i < 52; i++)
	    tired.attack("the target");

    std::cout << std::endl;

	std::cout << "========== Construction chaining =========="
		<< std::endl;

	{
		ScavTrap temporary("Temporary");
		std::cout << "Temporary ScavTrap is alive" << std::endl;
	}

	std::cout << "Temporary ScavTrap has been destroyed" << std::endl;

	std::cout << std::endl;

	std::cout << "========== End of main ==========" << std::endl;

	return 0;
}