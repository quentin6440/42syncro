#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.h"
#include <string>

class HumanB
{
    private:
        std::string     _name;
        Weapon*         _weapon;

    public:
        HumanB(const std::string& name);
        void    setWeapon(Weapon& type);
        void attack() const;
};

#endif