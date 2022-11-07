#ifndef _Monster_HPP_
#define _Monster_HPP_

#include "Creature.hpp"

class Monster : public Creature {

    public:
        Monster();
        Monster(std::string name, unsigned int option);
        ~Monster();
    };

#endif // _Monster_HPP_