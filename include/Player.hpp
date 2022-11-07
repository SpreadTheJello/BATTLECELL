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

enum p_Purchases{
  BOUGHT, // purchased
  CANNOT, // cannot afford
  IMPROVE // cannot improve stat further
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
    unsigned int getCurrentMaxHP() const;

    unsigned int getMaxDodge() const;
    unsigned int getBaseDodge() const;

    unsigned int getMaxArmor() const; 
    unsigned int getBaseArmor() const;

    unsigned int getMaxDamage() const;
    unsigned int getBaseDamage() const;

    

    bool ImproveSustain(int up);
    bool ImproveHP(int up);
    bool ImproveDodge(int up);
    bool ImproveDamage(int up);
    bool ImproveArmor(int up);



    p_Purchases BuyHealth();
    p_Purchases BuyDamage();
    p_Purchases BuyDodge();
    p_Purchases BuyArmor();
    p_Purchases BuySustain();

    bool Pay(unsigned int goldCost);
    void Reward(unsigned int gold);

};

#endif // _PLAYER_HPP_