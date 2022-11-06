#include <iostream>

#include "Creature.hpp"

class Rogue : public Creature {
     public: 
     Rogue() {
          string name = "Rogue";
          unsigned int maxhp = 20;
          unsigned int currentHP = 20;
          unsigned int damage = 10;
          unsigned int armor = 0; 
          unsigned int dodge = 40;
          unsigned int sustain = 15;
     }
};

