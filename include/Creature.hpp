// Base Creature Class
// Header

#include <string>
using namespace std;

#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_

class Creature {
  protected:
    string name;
    unsigned int maxHP;
    unsigned int currentHP;
    unsigned int damage;
    unsigned int armor;
    unsigned int dodge;

  public:
    Creature(string name, unsigned int hp, unsigned int dam, unsigned int arm, unsigned int dog);
    Creature(Creature& creature);

    ~Creature();

    string getName();


    // Functions for Combat
    bool isAlive(); // return (currentHP>0);

    bool DealDamage(int damage); // Calculates damage creature takes
    void Heal(); // Heals taken damage
    unsigned int CurrentHealth(); // returns;

    unsigned int GetDodge();

    void ImproveHP(int up);
    


};

#endif