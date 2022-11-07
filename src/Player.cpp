//initiate Player Class
#include "Player.hpp"
using namespace std;

unsigned int static statGoldCost = 2;

Player::Player(string name, p_Classes option) {
     this->name = name;
     switch(option) {
          case p_Classes::CHAMPION:
               this->maxHP = 40;
               this->currentHP = 40;
               this->damage = 10;
               this->armor = 5;
               this->dodge = 0;
               this->sustain = 20;
               break;
          case p_Classes::PALADIN:
               this->maxHP = 30; 
               this->currentHP = 30;
               this->damage = 5;
               this->armor = 10;
               this->dodge = 0;
               this->sustain = 30;
               break;
          case p_Classes::RANGER:
               this->maxHP = 20; 
               this->currentHP = 20;
               this->damage = 8;
               this->armor = 5; 
               this->dodge = 30;
               this->sustain = 20;
               break;
          case p_Classes::ROGUE:
               this->maxHP = 20;
               this->currentHP = 20;
               this->damage = 10;
               this->armor = 0; 
               this->dodge = 40;
               this->sustain = 15;
               break;
          case p_Classes::ADVENTURER:
               this->maxHP = 30;
               this->currentHP = 30;
               this->damage = 8;
               this->armor = 10;
               this->dodge = 15;
               this->sustain = 20;
               break;
     }

     gold = 5;

}

unsigned int Player::getSustain() {
     return sustain;
}



// Improve Functions

bool Player::ImproveSustain(int up) {
     if (sustain == maxSustain){
          return false;
     }
     else if (sustain + up > maxSustain){
          sustain = maxSustain;
     }
     else{
          sustain += up;
     }
     return true;
}
bool Player::ImproveHP(int up) {
     if (currentHP == maxHP){
          return false;
     }
     else if (currentHP + up > maxHP){
          currentHP = maxHP;
     }
     else{
          currentHP += up;
     }
     return true;
}
bool Player::ImproveDodge(int up) {
     if (dodge == maxDodge){
          return false;
     }
     else if (dodge + up > maxDodge){
          dodge = maxDodge;
     }
     else{
          dodge += up;
     }
     return true;
}
bool Player::ImproveDamage(int up) {
     if (damage == maxDamage){
          return false;
     }
     else if (damage + up > maxDamage){
          damage = maxDamage;
     }
     else{
          damage += up;
     }
     return true;
}

bool Player::ImproveArmor(int up) {
     if (armor == maxArmor){
          return false;
     }
     else if (armor + up > maxArmor){
          armor = maxArmor;
     }
     else{
          armor += up;
     }
     return true;
}



// Buy Stat functions

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


// Shopping values

bool Player::Pay(unsigned int goldCost) {
     if (gold < goldCost)
          return false;
     else
          gold -= goldCost;
     return true;
}

void Player::Reward(unsigned int goldObtained) {
     gold = gold + goldObtained;
}

