// Base Creature Class
// Definitions
#include <string>
#include <random>
#include <time.h>
#include "Creature.hpp"

using namespace std;

//
Creature::Creature() {
    m_logger = new Console();
}


//
Creature::~Creature() {
    delete m_logger;
}

//
Creature::Creature(string name, unsigned int hp, unsigned int dam, unsigned int arm, unsigned int dog) {
    this->name = name;
    this->currentHP = hp;
    this->maxHP = hp;
    this->damage = dam;
    this->armor = arm;
    this->dodge = dog;
}



//
string Creature::getName() const{
    return this->name;
};



// return (currentHP>0);
bool Creature::isAlive() {
    return this->currentHP > 0;
}



// Calculates damage creature takes and reduces currentHealth accordingly. Return false if creature dies, true if still alive.
bool Creature::DealDamage(int amount) {
    int reduction = floor(2 * amount / 3);
    if (reduction > this->armor )
        reduction = this->armor;
    if(this->currentHP - (amount-reduction) <= 0)
        currentHP = 0;
    else
        this->currentHP -= (amount-reduction);
    return isAlive();
}



// Heals taken damage.
void Creature::Heal(int amount) {
    if(this->currentHP + amount >= this->maxHP)
        this->currentHP = this->maxHP;
    else
        this->currentHP += amount;
}

unsigned int Creature::CurrentHealth() {
    return this->currentHP;
}

unsigned int Creature::GetDodge() {
    return this->dodge;
}
unsigned int Creature::GetArmor() {
    return this->armor;
}
unsigned int Creature::GetDamage() {
    return this->damage;
}


//attack on an enemy
void Creature::combatAction(Creature& enemy) {
    
    //Dodge Check
    srand(time(NULL));
    if(rand() % 100 < enemy.GetDodge()) { // Dodges
        // m_logger->writeLine(this->name() + "");
    }
    else { // Deals Damage
        enemy.DealDamage(this->damage);
    }
}

