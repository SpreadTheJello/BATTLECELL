#include <random>
#include <time.h>
#include <chrono>
#include <thread>

#include "Creature.hpp"

using namespace std;

// Basic Enemy: Zombie. Makes default attacks.
class Zombie : public Creature {
  public:
    Zombie() {
        this->name = "Zombie";
        this->maxHP = 18;
        this->currentHP = 18;
        this->damage = 2;
        this->dodge = 10;
        this->armor = 4;
    }
};

// Side-Boss: Daemon. Has a chance of making an unmissable (ignores dodge) attack at 1/2 damage.
class Daemon : public Creature {
  public:
    Daemon() {
        this->name = "Daemon";
        this->maxHP = 42;
        this->currentHP = 42;
        this->damage = 10;
        this->dodge = 30;
        this->armor = 6;
    }

    // Two possible attacks, normal attack and an unmissable attack (at 1/2 damage).
    void combatAction(Creature* enemy) {
        srand(time(NULL));
        if(rand() % 4 == 3) { // 25% chance of alt. attack
            this_thread::sleep_for(chrono::milliseconds(400));
            m_logger->WriteLine(this->name + " attacks with a chaotic force!");
            this_thread::sleep_for(chrono::milliseconds(400));
            m_logger->WriteLine(enemy->getName() + " tries to avoid the attack, but it cannot miss!");
            enemy->DealDamage( floor(this->damage / 2) );
        } else {
          this->Creature::combatAction(enemy);
        }
    }
};



/*
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