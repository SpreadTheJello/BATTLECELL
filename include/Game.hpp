#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "Console.hpp"
#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"



class Game {
    private:
        Console* m_logger = nullptr;
        Player* m_player = nullptr;

        GAMESTATE m_gameState = GAMESTATE::MENU;

        void TransitionState(GAMESTATE state);

    public:
        Game();
        ~Game();

        // returns true to keep playing, or false to end the game loop
        bool ProcessCommand(std::string command, std::string mainArg, std::string fullArg);
};

#endif // _GAME_HPP_