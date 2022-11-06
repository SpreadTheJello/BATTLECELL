#include <iostream>

#include "Creature.hpp"

class Champion : public Creature {
     public: 
     Champion() {
          string name = "Champion";
          unsigned int maxhp = 40;
          unsigned int currentHP = 40;
          unsigned int damage = 10;
          unsigned int armor = 5;
          unsigned int dodge = 0;
          unsigned int sustain = 20;
     }
};