#ifndef _Monster_HPP_
#define _Monster_HPP_

#include "Creature.hpp"
using namespace std;

class Monster : public Creature {

    public:
        Monster(string& name, unsigned int option);
        ~Monster();
    };

#endif // _Monster_HPP_