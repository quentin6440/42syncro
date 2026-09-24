#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.h"
#include <string>

class HumanA
{
    private:
        std::string     _name;
        Weapon&         _weapon;

    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;
};

#endif