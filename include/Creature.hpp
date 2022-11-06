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

    bool DealDamage(int amount); // Calculates damage creature takes and reduces currentHealth accordingly.
    void Heal(int amount); // Heals taken damage.
    unsigned int CurrentHealth(); // prints current health out of maximum health;

    unsigned int GetDodge();
    unsigned int GetArmor();
    unsigned int GetDamage();

    void ImproveHP(int up);
    void ImproveDodge(int up);
    void ImproveDamage(int up);
    void ImproveArmor(int up);
    


};

#endif