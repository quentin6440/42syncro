#include "../inc/FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
	: ClapTrap()
{
	_name = "Default FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap default constructor called for the object named: "
		<< _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for the object named: "
		<< _name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for the object named: "
		<< _name << std::endl;
}

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap custom constructor called for the object named: "
		<< _name << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name
			<< " cannot attack because it has no hit points left."
			<< std::endl;
	else if (_energyPoints <= 0)
		std::cout << "FragTrap " << _name
			<< " cannot attack because it has no energy points left."
			<< std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " requests a positive high five!" << std::endl;
}