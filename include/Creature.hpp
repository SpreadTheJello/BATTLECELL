// Base Creature Class
// Header
#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_

#include "Console.hpp"
#include <string>

class Creature {
  protected:
    Console* m_logger = nullptr;
    
    std::string name;
    unsigned int maxHP;
    unsigned int currentHP;
    unsigned int damage;
    unsigned int armor;
    unsigned int dodge;
    unsigned int sustain;

  public:
    Creature();
    Creature(std::string name, unsigned int hp, unsigned int dam, unsigned int arm, unsigned int dog);
    Creature(Creature& creature);

    ~Creature();

    std::string getName() const;
    unsigned int CurrentHealth() const;
    unsigned int GetMaxHP() const;
    unsigned int GetDodge() const;
    unsigned int GetArmor() const;
    unsigned int GetDamage() const;
    
    // Functions for Combat
    bool isAlive(); // return (currentHP>0);

    bool DealDamage(int amount); // Calculates damage creature takes and reduces currentHealth accordingly. Return false if creature dies, true if still alive.
    void Heal(int amount); // Heals taken damage.
    
    virtual void combatAction(Creature* enemy);
    void combatStatus();
    
    std::string healthBar();

};

#endif