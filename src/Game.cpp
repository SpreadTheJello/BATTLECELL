#include "Game.hpp"

#include <cmath>

Game::Game() {
	m_logger = new Console();
}

Game::~Game() {
	if (m_logger != nullptr) delete m_logger;
}


// returns true to keep playing, or false to end the game loop
bool Game::ProcessCommand(std::string command, std::string mainArg, std::string fullArg) {
	// quit
	if (command == "exit" || command == "quit") {
        m_logger->WriteLine("Goodbye!");
        return false;
    }
	else {
		m_logger->WriteCommandNotFound(command);
		return true;
	}
	if (command == "new"){

	}

	return true;
}
