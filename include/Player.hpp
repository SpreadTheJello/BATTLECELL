#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Creature.hpp"

enum p_Classes{
  ADVENTURER, 
  CHAMPION, 
  PALADIN, 
  RANGER, 
  ROGUE
};

class Player : public Creature {
  private:
    unsigned int gold;

    unsigned int baseSustain;
    unsigned int maxSustain;
    unsigned int currentSustain;

    unsigned int baseHealthStat;
    unsigned int maxHealthStat;

    unsigned int baseDodge;
    unsigned int maxDodge;

    unsigned int baseArmor;
    unsigned int maxArmor;

    unsigned int baseDamage;
    unsigned int maxDamage;

  public:
    
    Player(std::string name, p_Classes option);
    ~Player();


    unsigned int getGold() const;

    unsigned int getSustain() const;
    unsigned int getMaxSustain() const;
    unsigned int getBaseSustain() const;

    unsigned int getMaxHealthStat() const;
    unsigned int getBaseHealthStat() const;

    unsigned int getMaxDodge() const;
    unsigned int getBaseDodge() const;

    unsigned int getMaxArmor() const; 
    unsigned int getBaseArmor() const;

    unsigned int getMaxDamage() const;
    unsigned int getBaseDamage() const;

    void printStats();
    void combatStatus();

    int rest();

    bool ImproveSustain(int up);
    bool ImproveHP(int up);
    bool ImproveDodge(int up);
    bool ImproveDamage(int up);
    bool ImproveArmor(int up);

    void MassImprovement();

    bool BuyHealth();
    bool BuyDamage();
    bool BuyDodge();
    bool BuyArmor();
    bool BuySustain();

    bool Pay(unsigned int goldCost);
    void Reward(unsigned int gold);

};

#endif // _PLAYER_HPP_