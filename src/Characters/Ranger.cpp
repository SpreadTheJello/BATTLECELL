#include <iostream>

#include "Creature.hpp"

class Ranger : public Creature {
     public: 
     Ranger() {
          string name = "Ranger";
          unsigned int maxhp = 20; 
          unsigned int currentHP = 20;
          unsigned int damage = 8;
          unsigned int armor = 5; 
          unsigned int dodge = 30;
          unsigned int sustain = 20;
     }
};