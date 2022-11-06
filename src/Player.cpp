//initiate Player Class
#include "Player.hpp"

void Player::ImproveSustain(int up) {
     sustain = sustain + up;
}

bool Player::Pay(unsigned int goldCost) {
     gold = gold - goldCost;
}

void Player::Reward(unsigned int goldObtained) {
     gold = gold + goldObtained;
}
