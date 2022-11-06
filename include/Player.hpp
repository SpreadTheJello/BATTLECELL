#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Creature.hpp"

class Player : public Creature {
  private:
    unsigned int gold;
    unsigned int sustain;

  public:
    Player(std::string& name, unsigned int option);
    ~Player();

    void ImproveSustain(int up);

    bool Pay(unsigned int goldCost);

    void Reward(unsigned int gold);

};

#endif // _PLAYER_HPP_