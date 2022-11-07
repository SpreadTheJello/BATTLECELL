#include "Game.hpp"
#include "Player.hpp"

#include <cmath>
#include <time.h>

using namespace	std;

Game::Game() {
	m_logger = new Console();
}

Game::~Game() {
	if (m_logger != nullptr) delete m_logger;
}

void Game::TransitionState(GAMESTATE state) {
	switch (state) {
		case GAMESTATE::TITLE:
			break;
		case GAMESTATE::MENU:
			m_gameState = GAMESTATE::MENU;
			m_logger->WriteLine("Menu: From here, you can start a {new} game, or {exit}! At any time, {help} will tell you the available commands.");
			break;
		case GAMESTATE::GAME:
			m_gameState = GAMESTATE::GAME;
			m_logger->Write("You are in the game!");
			break;
		default:
			break;
	}
}

// returns true to keep playing, or false to end the game loop
bool Game::ProcessCommand(std::string command, std::string mainArg, std::string fullArg) {
	// quit
	if (command == "exit" || command == "quit") {
		if(m_gameState == GAMESTATE::GAME) {
			m_logger->WriteLine("Are you sure you want to quit, " + m_player->getName() + "? (y/n)");
			std::string input;
			std::getline(std::cin, input);
			if (input == "y" || input == "yes") {
				return false;
			}
			else {
				m_logger->WriteLine("Continuing game...");
				return true;
			}
		}
		else if (m_gameState == GAMESTATE::MENU) {
			m_logger->WriteLine("Game Over.");
        	return false;
		}
		else {
			m_logger->WriteCommandNotFound(command);
			return true;
		}
    }

	// help
	else if (command == "help"){
		m_logger->WriteLine("Fuck you no help");
		return true;
	}


	GAMESTATE transitionState = m_gameState;
	switch (m_gameState) {
		case GAMESTATE::TITLE:
			m_gameState = GAMESTATE::MENU;
			m_logger->WriteHelp(m_gameState);
			break;
			
		case GAMESTATE::MENU:
			if (command == "new"){
				transitionState = GAMESTATE::GAME;
				m_logger->WriteLine("Starting a new game!");
				m_logger->WriteLine("Please tell us your name: ");
				m_logger->Write("\n> ");
				std::string name;
				std::getline(std::cin, name);
				m_logger->WriteLine("Please chose your player role: {adventurer}, {rogue}, {ranger}, {paladin}, or {champion}");
				m_logger->WriteLine("You can also choose a {random} role!");
				m_logger->Write("\n> ");
				std::string role;
				std::getline(std::cin, role);
				if (role == "adventurer"){
					m_player = new Player(name, p_Classes::ADVENTURER);
					m_logger->printFile("adventurer", 50);
					m_logger->WriteLine("\n\nYou are an adventurer!");
				}
				else if (role == "rogue"){
					m_player = new Player(name, p_Classes::ROGUE);
					m_logger->printFile("rogue", 50);
					m_logger->WriteLine("\n\nYou are a rogue!");
				}
				else if (role == "ranger"){
					m_player = new Player(name, p_Classes::RANGER);
					m_logger->printFile("ranger", 50);
					m_logger->WriteLine("\n\nYou are a ranger!");
				}
				else if (role == "paladin"){
					m_player = new Player(name, p_Classes::PALADIN);
					m_logger->printFile("paladin", 50);
					m_logger->WriteLine("\n\nYou are a paladin!");
				}
				else if (role == "champion"){
					m_player = new Player(name, p_Classes::CHAMPION);
					m_logger->printFile("champion", 50);
					m_logger->WriteLine("\n\nYou are a champion!");
				}
				else if (role == "random"){
					srand(time(NULL));
					int random = rand() % 5;
					switch (random){
						case 0:
							m_player = new Player(name, p_Classes::ADVENTURER);
							m_logger->printFile("adventurer", 50);
							m_logger->WriteLine("\n\nYou are an adventurer!");
							break;
						case 1:
							m_player = new Player(name, p_Classes::ROGUE);
							m_logger->printFile("rogue", 50);
							m_logger->WriteLine("\n\nYou are a rogue!");
							break;
						case 2:
							m_player = new Player(name, p_Classes::RANGER);
							m_logger->printFile("ranger", 50);
							m_logger->WriteLine("\n\nYou are a ranger!");
							break;
						case 3:
							m_player = new Player(name, p_Classes::PALADIN);
							m_logger->printFile("paladin", 50);
							m_logger->WriteLine("\n\nYou are a paladin!");
							break;
						case 4:
							m_player = new Player(name, p_Classes::CHAMPION);
							m_logger->printFile("champion", 50);
							m_logger->WriteLine("\n\nYou are a champion!");
							break;
					}
				}
				else{
					m_logger->WriteLine("Invalid role! Please try again.");
					return true;
				}
			}
			else {
				m_logger->WriteCommandNotFound(command);
				return true;
			}
			break;
		case GAMESTATE::GAME:
			if (command == "new") {
				m_logger->WriteLine("You are already in the game!");
			}
			if (command == "status"){
				m_logger->WriteLine(to_string(m_player->CurrentHealth()));
			}
			break;
		default:
			break;
	}
	if(transitionState != m_gameState){
		TransitionState((GAMESTATE)transitionState);
	}
	
	return true;
}
