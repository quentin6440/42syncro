#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie
{
    private:
        std::string _name;
        
    public:
        Zombie();
        ~Zombie();
		void setName(std::string name);
        void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif