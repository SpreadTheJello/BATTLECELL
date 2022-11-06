#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "Console.hpp"
using namespace std;

class Game {
    private:
        Console* m_logger = nullptr;

    public:
        Game();
        ~Game();

        // returns true to keep playing, or false to end the game loop
        bool ProcessCommand(string command, std::string mainArg, std::string fullArg);
};

#endif // _GAME_HPP_