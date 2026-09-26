#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap();                                 //default constructor
        ClapTrap(const ClapTrap& other);            //copy constructor
        ClapTrap& operator=(const ClapTrap& other); //copy assignment operator
        virtual ~ClapTrap();                                //default destructor

        ClapTrap(const std::string& name);  //custom constructor (name init as parameter)

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif