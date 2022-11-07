//initiate Player Class
#include "Player.hpp"
using namespace std;

unsigned int static const statGoldCost = 2;

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
               this->damage = 16;

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
               this->baseDamage = 80;
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

// Returns Current maxHP
unsigned int Player::getCurrentMaxHP() const{
     return this->maxHP;
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



/* Improve Stat Functions */

// Improves Sustain stat up to its maximum
bool Player::ImproveSustain(int up) {
     if (this->sustain == this->maxSustain){
          return false;
     }
     else if (this->sustain + up > this->maxSustain){
          this->sustain = this->maxSustain;
     }
     else{
          this->sustain += up;
     }
     return true;
}

// Improves MaxHP stat up to its maximum
bool Player::ImproveHP(int up) {
     if (this->maxHP == this->maxHealthStat){
          return false;
     }
     else if (this->maxHP + up > this->maxHealthStat){
          this->maxHP =this-> maxHealthStat;
     }
     else{
          this->maxHP += up;
     }
     return true;
}

// Improves Dodge stat up to its maximum
bool Player::ImproveDodge(int up) {
     if (this->dodge == this->maxDodge){
          return false;
     }
     else if (this->dodge + up > this->maxDodge){
          this->dodge = this->maxDodge;
     }
     else{
          this->dodge += up;
     }
     return true;
}

// Improves Damage stat up to its maximum
bool Player::ImproveDamage(int up) {
     if (this->damage == this->maxDamage){
          return false;
     }
     else if (this->damage + up > this->maxDamage){
          this->damage = this->maxDamage;
     }
     else{
          this->damage += up;
     }
     return true;
}

// Improves Armor stat up to its maximum
bool Player::ImproveArmor(int up) {
     if (this->armor == this->maxArmor){
          return false;
     }
     else if (this->armor + up > this->maxArmor){
          this->armor = this->maxArmor;
     }
     else{
          this->armor += up;
     }
     return true;
}



/* Buy Stat Improvement functions */

// !!!!!!!!!!!!!!!!!!    TODO    !!!!!!!!!!!!!!!!!!
/* Decide whether to return enum value or print with m_logger */

// Attempts to purchase Health Improvement 
p_Purchases Player::BuyHealth() {
     if (this->Pay(statGoldCost)) {
          unsigned int improvement = (this->maxHealthStat - this->baseHealthStat) / 10;
          if (ImproveHP(improvement)) {
               return p_Purchases::BOUGHT;
          }
          return p_Purchases::IMPROVE;
     } else 
          return p_Purchases::CANNOT;
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

