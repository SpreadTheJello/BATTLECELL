#include <iostream>

#include "Creature.hpp"

class Bandit : public Creature {
     public: 
     Bandit() {
          string name = "Bandit";
          unsigned int maxhp = 0;
          unsigned int currentHP = 0;
          unsigned int damage = 0;
          unsigned int armor = 0; 
          unsigned int dodge = 0;
          unsigned int sustain = 0;
     }
};
