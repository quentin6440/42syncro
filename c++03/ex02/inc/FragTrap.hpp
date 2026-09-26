#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		FragTrap(const std::string &name);
		~FragTrap();

		virtual void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif