/*
#include <iostream>

#include "Monster.hpp"

//concept for monster list
//the main class is the type of monster object we are making then the sub classes represent the specific stats
//of the monster. This is done for both the bosses, semi bosses, average mob

class Boss : public Monster {
     class Tiamat{
          public:
               Tiamat(){
                    this->name = "";
                    this->maxHP = 100;
                    this->currentHP = 100;
                    this->damage = 60;
                    this->armor = 50;
                    this->dodge = 20;
               }

               int combatAction(Creature& enemy){
                    //adds 2 extra damage every thrid attack to represent like fire aspect
               }
     }

     class elderKracken{
          public:
               elderKracken(){
                    this->name = "Giscol";
                    this->maxHP = 80;
                    this->currentHP = 80;
                    this->damage = 30;
                    this->armor = 40;
                    this->dodge = 60;
               }

               int combatAction(Creature& enemy){
                    //has a chance of hitting twice because of multiple tentacles
               }
     }

};


class miniBoss : public Monster{
     class Gargoyle{
          public:
               Gargoyle(){
                    this->name = "Dr.RockSolid";
                    this->maxHP = 80;
                    this->currentHP = 80;
                    this->damage = 30;
                    this->armor = 40;
                    this->dodge = 60;
               }
     }
};

classes averageMob : public Monster{
     class Zombie{
          public:
               Zombie{
                    this->name = "Giscol";
                    this->maxHP = 80;
                    this->currentHP = 80;
                    this->damage = 30;
                    this->armor = 40;
                    this->dodge = 60;
               }
     }
}
*/