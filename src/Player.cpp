//initiate Player Class
#include "Player.hpp"

#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

unsigned int static const statGoldCost = 3;

// Player Constructor
Player::Player(string name, p_Classes option) {
     this->name = name;
     
     // Sets stats based on Player Class option
     switch(option) {
          case p_Classes::ADVENTURER:
               this->maxHealthStat = 50;
               this->baseHealthStat = 30;
               this->maxHP = 30;
               this->currentHP = 30;

               this->maxDamage = 28;
               this->baseDamage = 8;
               this->damage = 8;

               this->maxArmor = 15;
               this->baseArmor = 5;
               this->armor = 5;

               this->maxDodge = 35;
               this->baseDodge = 15;
               this->dodge = 15;

               this->maxSustain = 50;
               this->baseSustain = 20;
               this->sustain = 20;
               break;
          case p_Classes::CHAMPION:
               this->maxHealthStat = 80;
               this->baseHealthStat = 40;
               this->maxHP = 40;
               this->currentHP = 40;

               this->maxDamage = 40;
               this->baseDamage = 10;
               this->damage = 10;

               this->maxArmor = 15;
               this->baseArmor = 5;
               this->armor = 5;

               this->maxDodge = 10;
               this->baseDodge = 0;
               this->dodge = 0;

               this->maxSustain = 50;
               this->baseSustain = 20;
               this->sustain = 20;
               break;
          case p_Classes::PALADIN:
               this->maxHealthStat = 50;
               this->baseHealthStat = 30;
               this->maxHP = 30;
               this->currentHP = 30;

               this->maxDamage = 16;
               this->baseDamage = 6;
               this->damage = 6;

               this->maxArmor = 40;
               this->baseArmor = 10;
               this->armor = 10;

               this->maxDodge = 10;
               this->baseDodge = 0;
               this->dodge = 0;

               this->maxSustain = 80;
               this->baseSustain = 40;
               this->sustain = 40;
               break;
          case p_Classes::RANGER:
               this->maxHealthStat = 50;
               this->baseHealthStat = 30;
               this->maxHP = 30;
               this->currentHP = 30;

               this->maxDamage = 28;
               this->baseDamage = 8;
               this->damage = 8;

               this->maxArmor = 15;
               this->baseArmor = 5;
               this->armor = 5;

               this->maxDodge = 60;
               this->baseDodge = 30;
               this->dodge = 30;

               this->maxSustain = 50;
               this->baseSustain = 20;
               this->sustain = 20;
               break;
          case p_Classes::ROGUE:
               this->maxHealthStat = 40;
               this->baseHealthStat = 20;
               this->maxHP = 20;
               this->currentHP = 20;

               this->maxDamage = 40;
               this->baseDamage = 10;
               this->damage = 10;

               this->maxArmor = 10;
               this->baseArmor = 0;
               this->armor = 0;

               this->maxDodge = 80;
               this->baseDodge = 40;
               this->dodge = 40;

               this->maxSustain = 25;
               this->baseSustain = 15;
               this->sustain = 15;
               break;
     }

     this->gold = 5; //player starts off with 5 gold
}



/* Getters */ 


// Returns player's gold
unsigned int Player::getGold() const{
     return this->gold;
}
// Returns player's Sustain stat
unsigned int Player::getSustain() const{
     return this->sustain;
}

// Returns MaxSustain
unsigned int Player::getMaxSustain() const{
     return this->maxSustain;
}
// Returns BaseSustain
unsigned int Player::getBaseSustain() const{
     return this->baseSustain;
}

// Returns MaxHealthStat
unsigned int Player::getMaxHealthStat() const{
     return this->maxHealthStat;
}
// Returns BaseHealthStat
unsigned int Player::getBaseHealthStat() const{
     return this->baseHealthStat;
}

// Returns MaxDodge
unsigned int Player::getMaxDodge() const{
     return this->maxDodge;
}
// Returns BaseDodge
unsigned int Player::getBaseDodge() const{
     return this->baseDodge;
}

// Returns MaxArmor
unsigned int Player::getMaxArmor() const{
     return this->maxArmor;
}
// Returns BaseArmor
unsigned int Player::getBaseArmor() const{
     return this->baseArmor;
}

// Returns MaxDamage
unsigned int Player::getMaxDamage() const{
     return this->maxDamage;
}
// Returns BaseDamage
unsigned int Player::getBaseDamage() const{
     return this->baseDamage;
}



/* Status Functions */


// Prints player stats. For {status} outside of combat.
void Player::printStats() {
     m_logger->WriteLine("Your stats:");
     this_thread::sleep_for(chrono::milliseconds(400));
     m_logger->WriteLine("Health: " + this->healthBar() + "  (" + to_string(this->currentHP) + "/" + to_string(this->maxHP) + ") --- max. " + to_string(this->maxHealthStat));
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Damage: " + to_string(this->damage) + " --- max. " + to_string(this->maxDamage));
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Armor: " + to_string(this->armor) + " --- max. " + to_string(this->maxArmor));
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Dodge: " + to_string(this->dodge) + "% --- max. " + to_string(this->maxDodge) + "%");
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Sustain: " + to_string(this->sustain) + "% --- max. " + to_string(this->maxSustain) + "%");
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("\nGold: " + to_string(this->gold));
}

// Player combat status. Overrides Creature::combatStatus
void Player::combatStatus() {
     m_logger->WriteLine("Your status:");
     this_thread::sleep_for(chrono::milliseconds(400));
     m_logger->WriteLine("Health: " + this->healthBar() + "  (" + to_string(this->currentHP) + "/" + to_string(this->maxHP) + ")");
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Damage: " + to_string(this->damage));
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Armor: " + to_string(this->armor));
     this_thread::sleep_for(chrono::milliseconds(50));
     m_logger->WriteLine("Dodge: " + to_string(this->dodge) + "%");
}


// Performs a rest action
int Player::rest() {
     this->Heal(floor(this->maxHP * this->sustain / 100));
     return floor(this->maxHP * this->sustain / 100);
}



/* Improve Stat Functions */


// Improves Sustain stat up to its maximum
bool Player::ImproveSustain(int up) {
     if (this->sustain == this->maxSustain){
          m_logger->WriteLine("Cannot improve Sustain further.");
          return false;
     }
     else if (this->sustain + up > this->maxSustain){
          this->sustain = this->maxSustain;
          m_logger->WriteLine("Improved Sustain to maximum.");
     }
     else{
          this->sustain += up;
          m_logger->WriteLine("Improved Sustain by " + to_string(up) + ".");
     }
     return true;
}

// Improves MaxHP stat up to its maximum
bool Player::ImproveHP(int up) {
     if (this->maxHP == this->maxHealthStat){
          m_logger->WriteLine("Cannot improve Max HP further.");
          return false;
     }
     else if (this->maxHP + up > this->maxHealthStat){
          this->maxHP = this->maxHealthStat;
          this->Heal(up);
          m_logger->WriteLine("Improved Max HP to maximum.");
     }
     else{
          this->maxHP += up;
          this->Heal(up);
          m_logger->WriteLine("Improved Max HP by " + to_string(up) + ".");
     }
     return true;
}

// Improves Dodge stat up to its maximum
bool Player::ImproveDodge(int up) {
     if (this->dodge == this->maxDodge){
          m_logger->WriteLine("Cannot improve Dodge further.");
          return false;
     }
     else if (this->dodge + up > this->maxDodge){
          this->dodge = this->maxDodge;
          m_logger->WriteLine("Improved Dodge to maximum.");
     }
     else{
          this->dodge += up;
          m_logger->WriteLine("Improved Dodge by " + to_string(up) + ".");
     }
     return true;
}

// Improves Damage stat up to its maximum
bool Player::ImproveDamage(int up) {
     if (this->damage == this->maxDamage){
          m_logger->WriteLine("Cannot improve Damage further.");
          return false;
     }
     else if (this->damage + up > this->maxDamage){
          this->damage = this->maxDamage;
          m_logger->WriteLine("Improved Damage to maximum.");
     }
     else{
          this->damage += up;
          m_logger->WriteLine("Improved Damage by " + to_string(up) + ".");
     }
     return true;
}

// Improves Armor stat up to its maximum
bool Player::ImproveArmor(int up) {
     if (this->armor == this->maxArmor){
          m_logger->WriteLine("Cannot improve Armor further.");
          return false;
     }
     else if (this->armor + up > this->maxArmor){
          this->armor = this->maxArmor;
          m_logger->WriteLine("Improved Armor to maximum.");
     }
     else{
          this->armor += up;
          m_logger->WriteLine("Improved Armor by " + to_string(up) + ".");
     }
     return true;
}

// Improves all stats by one "stage"
void Player::MassImprovement() {
     unsigned int improvement;
     // Improve HP
     improvement = (this->maxHealthStat - this->baseHealthStat) / 10;
     ImproveHP(improvement);

     // Improve Damage
     improvement = (this->maxDamage - this->baseDamage) / 10;
     ImproveDamage(improvement);

     // Improve Dodge
     improvement = (this->maxDodge - this->baseDodge) / 10;
     ImproveDodge(improvement);

     // Improve Armor
     improvement = (this->maxArmor - this->baseArmor) / 10;
     ImproveArmor(improvement);

     // Improve Sustain
     improvement = (this->maxSustain - this->baseSustain) / 10;
     ImproveSustain(improvement);
}


/* Buy Stat Improvement functions */


// Attempts to purchase Health Improvement. Returns false if unable.
bool Player::BuyHealth() {
     if(this->maxHP == this->maxHealthStat) {
          m_logger->WriteLine("Cannot improve Max HP further.");
          return false;
     } else if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxHealthStat - this->baseHealthStat) / 10;
          ImproveHP(improvement);
          return true;
     }
     m_logger->WriteLine("You cannot afford this improvement.");
     return false;
}

// Attempts to purchase Armor Improvement. Returns false if unable.
bool Player::BuyArmor() {
     if(this->armor == this->maxArmor) {
          m_logger->WriteLine("Cannot improve Armor further.");
          return false;
     } else if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxArmor - this->baseArmor) / 10;
          ImproveArmor(improvement);
          return true;
     }
     m_logger->WriteLine("You cannot afford this improvement.");
     return false;
}

// Attempts to purchase Damage Improvement. Returns false if unable.
bool Player::BuyDamage() {
     if(this->damage == this->maxDamage) {
          m_logger->WriteLine("Cannot improve Damage further.");
          return false;
     } else if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxDamage - this->baseDamage) / 10;
          ImproveDamage(improvement);
          return true;
     }
     m_logger->WriteLine("You cannot afford this improvement.");
     return false;
}

// Attempts to purchase Dodge Improvement. Returns false if unable.
bool Player::BuyDodge() {
     if(this->dodge == this->maxDodge) {
          m_logger->WriteLine("Cannot improve Dodge further.");
          return false;
     } else if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxDodge - this->baseDodge) / 10;
          ImproveHP(improvement);
          return true;
     }
     m_logger->WriteLine("You cannot afford this improvement.");
     return false;
}

// Attempts to purchase Sustain Improvement. Returns false if unable.
bool Player::BuySustain() {
     if(this->sustain == this->maxSustain) {
          m_logger->WriteLine("Cannot improve Sustain further.");
          return false;
     } else if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxSustain - this->baseSustain) / 10;
          ImproveHP(improvement);
          return true;
     }
     m_logger->WriteLine("You cannot afford this improvement.");
     return false;
}

// Attempts to subtract goldCost from player's gold. Returns false if cannot make sufficient payment.
bool Player::Pay(unsigned int goldCost) {
     if (this->gold < goldCost)
          return false;
     else
          this->gold -= goldCost;
     return true;
}

// Adds goldObtained to player's gold
void Player::Reward(unsigned int goldObtained) {
     this->gold += goldObtained;
}

