// Base Creature Class
// Definitions
#include <string>
#include <random>
#include <time.h>
#include <thread>
#include <chrono>
#include "Creature.hpp"

using namespace std;

// Deconstructor
Creature::~Creature() {
    delete m_logger;
}



/* Constructors */


// Default Constructor
Creature::Creature() {
    m_logger = new Console();

    this->name = "n/a";
    this->currentHP = 0;
    this->maxHP = 0;
    this->damage = 0;
    this->armor = 0;
    this->dodge = 0;
}

// NEW Constructor
Creature::Creature(string name, unsigned int hp, unsigned int dam, unsigned int arm, unsigned int dog) {
    m_logger = new Console();

    this->name = name;
    this->currentHP = hp;
    this->maxHP = hp;
    this->damage = dam;
    this->armor = arm;
    this->dodge = dog;
}

// Creature& Constructor
Creature::Creature(Creature& creature) {
    m_logger = new Console();
    
    this->name = creature.getName();
    this->currentHP = creature.CurrentHealth();
    this->maxHP = creature.GetMaxHP();
    this->armor = creature.GetArmor();
    this->dodge = creature.GetDodge();
    this->damage = creature.GetDamage();
}



/* Getters */


//Returns creature name
string Creature::getName() const{
    return this->name;
}
// Returns creature's current health
unsigned int Creature::CurrentHealth() const{
    return this->currentHP;
}
// Returns creature's max health
unsigned int Creature::GetMaxHP() const{
    return this->maxHP;
}
// Returns creature's dodge stat
unsigned int Creature::GetDodge() const{
    return this->dodge;
}
// Returns creature's armor stat
unsigned int Creature::GetArmor() const{
    return this->armor;
}
// Returns creature's damage stat
unsigned int Creature::GetDamage() const{
    return this->damage;
}



/* Combat Functions */

// return (currentHP>0);
bool Creature::isAlive() {
    return (this->currentHP > 0);
}

// Calculates damage creature takes and reduces currentHealth accordingly. Return false if creature dies, true if still alive.
bool Creature::DealDamage(int amount) {
    int reduction = floor(2 * amount / 3);
    if (reduction > this->armor )
        reduction = this->armor;
    if( ((int) this->currentHP) - (amount-reduction) <= 0)
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

// Default Combat Action: attack an enemy
void Creature::combatAction(Creature* enemy) {
    this_thread::sleep_for(chrono::milliseconds(400));
    m_logger->WriteLine(this->name + " attacks " + enemy->getName());

    //Dodge Check
    srand(time(NULL));
    if(rand() % 100 < enemy->GetDodge()) { // Dodges
    this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine("A miss! " + enemy->getName() + " dodges " + this->name + "'s attack.\n");
    }
    else { // Deals Damage
    this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine("A hit! " + this->name + " strikes " +  enemy->getName() + "!\n");
        enemy->DealDamage(this->damage);
    }
}

// returns Health Bar string
string Creature::healthBar() {
    string hBar = "[";
    int hIncrement = 2;
    int hpCounter = this->currentHP;
    while (hpCounter > 0) {
        hBar += "▒";
        hpCounter -= hIncrement;
    }
    hpCounter = this->maxHP - this->currentHP;
    while (hpCounter > 0) {
        hBar += " ";
        hpCounter -= hIncrement;
    }
    hBar += "]";
    return hBar;
}

// Displays the stats of given creature.
void Creature::combatStatus() {
    m_logger->WriteLine(this->name + "'s status:");
    this_thread::sleep_for(chrono::milliseconds(400));
    m_logger->WriteLine("Health: " + this->healthBar() + "  (" + to_string(this->currentHP) + "/" + to_string(this->maxHP) + ")");
    this_thread::sleep_for(chrono::milliseconds(50));
    m_logger->WriteLine("Damage: " + to_string(this->damage));
    this_thread::sleep_for(chrono::milliseconds(50));
    m_logger->WriteLine("Armor: " + to_string(this->armor));
    this_thread::sleep_for(chrono::milliseconds(50));
    m_logger->WriteLine("Dodge: " + to_string(this->dodge) + "%");
}

