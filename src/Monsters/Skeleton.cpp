#include <iostream>

#include "include/Creature.hpp"

class Skeleton : public Creature {
     public: 
     Skeleton() {
          string name = "Skeleton";
          unsigned int maxhp = 0;
          unsigned int currentHP = 0;
          unsigned int damage = 0;
          unsigned int armor = 0; 
          unsigned int dodge = 0;
          unsigned int sustain = 0;
     }
};