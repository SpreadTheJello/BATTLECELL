#include <iostream>
#include <string>

#include "include/Creature.hpp"

class Paladin : public Creature {
     public: 
     Paladin() {
          string name = "Paladin";
          unsigned int maxhp = 30; 
          unsigned int currentHP = 30;
          unsigned int damage = 5;
          unsigned int armor = 10;
          unsigned int dodge = 0;
          unsigned int sustain = 30;
     }
};