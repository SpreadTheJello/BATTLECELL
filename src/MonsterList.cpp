#include <random>
#include <time.h>
#include <chrono>
#include <thread>

#include "Creature.hpp"
#include "Player.hpp"

using namespace std;


/*  First Floor Enemies  */

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

// Basic Enemy: Skeleton. Makes default attacks.
class Skeleton : public Creature {
  public:
    Skeleton() {
        this->name = "Skeleton";
        this->maxHP = 11;
        this->currentHP = 11;
        this->damage = 4;
        this->dodge = 30;
        this->armor = 0;
    }
};

// Basic Enemy: Flaming Skull. Explodes after 3 turns if still alive, dealing damage based on its remaining health.
class FlamingSkull : public Creature {
  int delay;

  public:
    FlamingSkull() {
        this->name = "Flaming Skull";
        this->maxHP = 20;
        this->currentHP = 20;
        this->damage = 2;
        this->dodge = 40;
        this->armor = 0;

        delay = 0;
    }

    void combatAction(Creature* enemy) {
      if (delay == 3) {
        this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine(this->name + " explodes!");
        enemy->DealDamage(this->currentHP);
        this->currentHP = 0;
      }
      else {
        this->Creature::combatAction(enemy);
        delay++;
      }
    }
};

// First Floor Boss: Death Knight. Will either wind up their attack, increasing its damage, or strike (50% chance of either happening at a time).
class DeathKnight : public Creature {
  int windup;
  public:
    DeathKnight() {
      this->name = "Death Knight";
      this->maxHP = 60;
      this->currentHP = 60;
      this->damage = 5;
      this->dodge = 0;
      this->armor = 8;

      windup = 0;
    }

    // Winds up their heavy hitting attacks.
    void combatAction(Creature* enemy) {
      srand(time(NULL));
      if (rand() % 2 == 1){
        this->damage = 5 * (windup+1);
        this->Creature::combatAction(enemy);
        windup = 0;
        this->damage = 5;
      }
      else {
        this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine(this->name + " winds up their attack!");
        windup++;
      }
    }
};


// Side-Boss: Necromancer. Has two possible attacks: Sapping Ray, Blight (1/3 odds).
class Necromancer : public Creature {
  int blight;
  public:
    Necromancer() {
      this->name = "Necromancer";
      this->maxHP = 66;
      this->currentHP = 66;
      this->damage = 4;
      this->dodge = 15;
      this->armor = 0;

      blight = 1;
    }

    void combatAction(Creature* enemy) {
      srand(time(NULL));
      if(rand() % 3 == 0) {
        // Blight
        this_thread::sleep_for(chrono::milliseconds(400));
        blight++;
        this->damage = this->damage * blight;
        m_logger->WriteLine(this->name + " blights " + enemy->getName() + ".");
        m_logger->WriteLine(this->name + "'s attacks grow in strength.");
      }
      else {// Sapping Ray. Basic attack with chance to heal for attack's damage.
        this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine(this->name + " casts Sapping Ray against " + enemy->getName());

        // Dodge Check
        srand(time(NULL));
        if(rand() % 100 < enemy->GetDodge()) { // Dodges
          this_thread::sleep_for(chrono::milliseconds(400));
          m_logger->WriteLine("A miss! " + enemy->getName() + " dodges " + this->name + "'s attack.\n");
        }
        else { // Deals Damage
          this_thread::sleep_for(chrono::milliseconds(400));
          m_logger->WriteLine("A hit! " + this->name + " saps the life out of " +  enemy->getName() + "!\n");
          enemy->DealDamage(this->damage); // deals damage
          if(rand() % 2 == 0) { // 50% chance for heal effect
            this->Heal(this->damage); // heals for attack's damage
            m_logger->WriteLine(this->name + " heals itself.");
          }
        }
      }
    }
};

// Side-Boss: Vampire. Has 2 attacks: default, Vampiric Touch (1/3 odds)
class Vampire : public Creature {
  public:
    Vampire() {
      this->name = "Vampire";
      this->maxHP = 40;
      this->currentHP = 40;
      this->damage = 7;
      this->dodge = 35;
      this->armor = 3;
    }

    void combatAction(Creature* enemy) {
      srand(time(NULL));
      if (rand() % 3 == 2) { // Vampiric Touch
        this_thread::sleep_for(chrono::milliseconds(400));
        m_logger->WriteLine(this->name + " strikes with its Vampiric Touch " + enemy->getName() + ".");

        // Dodge Check
        srand(time(NULL));
        if(rand() % 100 < enemy->GetDodge()) { // Dodges
          this_thread::sleep_for(chrono::milliseconds(400));
          m_logger->WriteLine("A miss! " + enemy->getName() + " dodges " + this->name + "'s attack.\n");
        }
        else { // Deals Damage
          this_thread::sleep_for(chrono::milliseconds(400));
          m_logger->WriteLine("A hit! " + this->name + " steals " +  enemy->getName() + "'s life force!\n");
          enemy->DealDamage(this->damage*2); // deals double damage
          this->Heal(this->damage); // heals for half attack's damage
          m_logger->WriteLine(this->name + " heals itself from its attack.");
        }
      } else {
        this->Creature::combatAction(enemy);
      }
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







