#ifndef _Monster_HPP_
#define _Monster_HPP_

#include "Creature.hpp"

class Monster : public Creature {
    private:
        unsigned int maxHP;
        unsigned int currentHP;
        unsigned int damage;
        unsigned int armor;
        unsigned int dodge;

    public:
        Monster();
        Monster(std::string name, unsigned int option);
        ~Monster();
    };

#endif // _Monster_HPP_