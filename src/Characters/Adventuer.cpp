#include <iostream>

#include "include/Creature.hpp"
#include "include/Player.hpp"

class Adventuer : public Creature {
     public: 
     Adventuer() {
          string name = "Adventuer";
          unsigned int maxhp = 30; //TBD
          unsigned int currentHP = 30;
          unsigned int damage = 8;
          unsigned int armor = 10; //TBD
          unsigned int dodge = 15;
          unsigned int sustain = 20;
     }
};

