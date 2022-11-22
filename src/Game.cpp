#include "Game.hpp"
#include "Player.hpp"
#include "Floor.hpp"
#include "FloorList.cpp"

#include <cmath>
#include <time.h>
#include <random>

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
		case GAMESTATE::FLOOR:
			m_gameState = GAMESTATE::FLOOR;
			break;
		case GAMESTATE::COMBAT:
			m_gameState = GAMESTATE::COMBAT;
			m_logger->WriteLine("You are in combat with " + m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->getName() + ". You can use {attack} to attack, {status} to view stats of enemy, or {flee} to try to escape to a random nearby room.");
			break;
		case GAMESTATE::REST:
			m_gameState = GAMESTATE::REST;
			m_logger->WriteLine("Would you like to rest? (y/n)");
			break;
		case GAMESTATE::SHOP:
			m_gameState = GAMESTATE::SHOP;
			m_logger->printFile("shop", 50);
			srand(time(NULL));
			switch (rand() % 5) {
				case 0:
					m_logger->WriteLine("Welcome, stranger. You won't find a better merchant in these dungeons.");
					break;
				case 1:
					m_logger->WriteLine("Lamp oil? Rope? Bombs? I don't have any of those, but I can make you stronger... For a small fee.");
					break;
				case 2:
					m_logger->WriteLine("Shiba has wares, if you have coin.");
					break;
				case 3:
					m_logger->WriteLine("Got some rare things on sale, stranger.");
					break;
				case 4:
					m_logger->WriteLine("If I can't find you what you need, it can't be found in Battlecell.");
					break;
				default:
					break;
			}
			m_logger->WriteLine("\nYou can {buy} improvements to any of your stats, such as <health/damage/dodge/armor/sustain>.");
			break;
		default:
			break;
	}
}

// returns true to keep playing, or false to end the game loop
bool Game::ProcessCommand(std::string command, std::string mainArg, std::string fullArg) {
	// quit
	if (command == "exit" || command == "quit") {
		if(!(m_gameState == GAMESTATE::MENU)) {
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
		else {
			m_logger->WriteLine("Goodbye!\n");
        	return false;
		}
    }

	// help
	else if (command == "help"){
		m_logger->WriteHelp(m_gameState);
		return true;
	}

	
	GAMESTATE transitionState = m_gameState;
	switch (m_gameState) {
		case GAMESTATE::TITLE:
			m_gameState = GAMESTATE::MENU;
			break;
			
		case GAMESTATE::MENU:
			if (command == "new"){
				if(mainArg == "dev"){
					m_player = new Player("Dev", p_Classes::ADVENTURER);
					transitionState = GAMESTATE::FLOOR;
					m_floor = new FirstFloor();
					for(int i = 0;  i < m_floor->floorSize(); i++) {
						m_logger->WriteLine(to_string(i) + " { N:" + to_string(m_floor->getRoom(i)->getNorthRoom()) + "; E:"+ to_string(m_floor->getRoom(i)->getEastRoom()) + "; S:"+ to_string(m_floor->getRoom(i)->getSouthRoom()) + "; W:"+ to_string(m_floor->getRoom(i)->getWestRoom()) + " }");
					}
				}
				else{
					transitionState = GAMESTATE::GAME;
					m_logger->WriteLine("Starting a new game!");
					m_logger->WriteLine("Please tell us your name: ");
					m_logger->Write("\n> ");
					std::string name;
					std::getline(std::cin, name);
					m_logger->WriteLine("Hello, " + name + "!");
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
			else if (command == "status"){
				m_player->printStats();
			}
			else if (command == "start"){
				transitionState = GAMESTATE::FLOOR;
				m_logger->WriteLine("You adventure into the dungeon!");
				m_floor = new FirstFloor();
				m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
			}
			else{
				m_logger->WriteCommandNotFound(command);
				return true;
			}
			break;

		case GAMESTATE::FLOOR:
			if (command == "new") {
				m_logger->WriteLine("You are already in the game!");
			}
			else if (command == "status"){
				m_player->printStats();
			}
			else if(command == "display"){
				m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
				m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
			}
			else if(command == "go"){
				//for direction of travel
				if(mainArg == "north"){
					if(m_floor->traverse(0)){
						m_logger->WriteLine("You go north.");
						m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
						m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "MONSTER" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SIDEBOSS" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "FLOORBOSS"){
							transitionState = GAMESTATE::COMBAT;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "REST"){
							transitionState = GAMESTATE::REST;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SHOP"){
							transitionState = GAMESTATE::SHOP;
						}
					}
					else{
						m_logger->WriteLine("You can't go north.");
					}
				}
				else if(mainArg == "east"){
					if(m_floor->traverse(1)){
						m_logger->WriteLine("You go east.");
						m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
						m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "MONSTER" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SIDEBOSS" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "FLOORBOSS"){
							transitionState = GAMESTATE::COMBAT;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "REST"){
							transitionState = GAMESTATE::REST;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SHOP"){
							transitionState = GAMESTATE::SHOP;
						}
					}
					else{
						m_logger->WriteLine("You can't go east.");
					}
				}
				else if(mainArg == "south"){
					if(m_floor->traverse(2)){
						m_logger->WriteLine("You go south.");
						m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
						m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "MONSTER" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SIDEBOSS" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "FLOORBOSS"){
							transitionState = GAMESTATE::COMBAT;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "REST"){
							transitionState = GAMESTATE::REST;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SHOP"){
							transitionState = GAMESTATE::SHOP;
						}
					}
					else{
						m_logger->WriteLine("You can't go south.");
					}
				}
				else if(mainArg == "west"){
					if(m_floor->traverse(3)){
						m_logger->WriteLine("You go west.");
						m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
						m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "MONSTER" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SIDEBOSS" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "FLOORBOSS"){
							transitionState = GAMESTATE::COMBAT;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "REST"){
							transitionState = GAMESTATE::REST;
						}
						if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SHOP"){
							transitionState = GAMESTATE::SHOP;
						}
					}
					else{
						m_logger->WriteLine("You can't go west.");
					}
				}
				else{
					m_logger->WriteLine("Invalid direction! Please try again.");
				}
			}
			else{
				m_logger->WriteCommandNotFound(command);
				return true;
			}
			break;
		
		case GAMESTATE::COMBAT:
			if (command == "new") {
				m_logger->WriteLine("You are already in the game!");
			}
			else if (command == "status"){
				m_player->combatStatus();
				m_logger->WriteLine();
				m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->combatStatus();
			}
			else if(command == "display"){
				m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
				m_logger->WriteLine("You're in room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
			}
			else if(command == "attack"){
				m_player->combatAction(m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy());
				if(m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->isAlive()) {
					m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->combatAction(m_player);
					if(!m_player->isAlive()) {
						m_logger->printFile("gameover", 150);
						transitionState = GAMESTATE::MENU;
					}
				}
				
				if (!(m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->isAlive())) {
					m_logger->WriteLine("You have defeated the enemy!");

					/* loot enemy */
					if (m_floor->getRoom(m_floor->getCurrentRoom())->getType() == r_Type::FLOORBOSS) {
						// give a large amount of loot and progress to next floor
						int loot = (rand() % 5) + 9;
						m_player->Reward(loot);
						m_logger->WriteLine("You find " + to_string(loot) + " gold and progress to the next floor.");
					}
					else if (m_floor->getRoom(m_floor->getCurrentRoom())->getType() == r_Type::SIDEBOSS) {
						// improve all stats by 1 stage
						m_logger->WriteLine("You feel a new power course through your veins.\n");
						m_player->MassImprovement();
					}
					else {
						// basic monster kill, grant 1-3 gold
						int loot = (rand() % 3) + 1;
						m_player->Reward(loot);
						m_logger->WriteLine("You find " + to_string(loot) + " gold.");
					}
					m_floor->getRoom(m_floor->getCurrentRoom())->markCleared();
					transitionState = GAMESTATE::FLOOR;
				}
			}
			else if(command == "flee"){
				srand(time(NULL));
				int direction = rand() % 4;
				if (m_floor->getRoom(m_floor->getCurrentRoom())->getNearbyRooms()[direction] == -1) {
					m_logger->WriteLine("You tried to flee, but failed.");
					m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->combatAction(m_player);
					if(!m_player->isAlive()) {
						system("clear");
						m_logger->printFile("gameover", 150);
						transitionState = GAMESTATE::MENU;
					}
				}
				else {
					m_floor->traverse(direction);
					transitionState = GAMESTATE::FLOOR;
					m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
					m_logger->WriteLine("You flee into a nearby room: " + m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString());
					if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "MONSTER" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SIDEBOSS" || m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "FLOORBOSS"){
						transitionState = GAMESTATE::COMBAT;
						m_logger->WriteLine("You are in combat with " + m_floor->getRoom(m_floor->getCurrentRoom())->getEnemy()->getName() + ". You can use {attack} to attack, {status} to view stats of enemy, or {flee} to try to escape to a random nearby room.");
					}
					if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "REST"){
						transitionState = GAMESTATE::REST;
					}
					if(m_floor->getRoom(m_floor->getCurrentRoom())->getRoomString() == "SHOP"){
						transitionState = GAMESTATE::SHOP;
					}
				}
			}
			else{
				m_logger->WriteCommandNotFound(command);
				return true;
			}
			break;

		case GAMESTATE::SHOP:
			if (command == "new") {
				m_logger->WriteLine("You are already in the game!");
			}
			else if (command == "status"){
				m_player->printStats();
			}
			else if(command == "view"){
				m_logger->WriteLine("\nYou can {buy} improvements to any of your stats, such as <health/damage/dodge/armor/sustain>.");
			}
			else if(command == "buy"){
				if (mainArg == "health") {
					m_player->BuyHealth();
				}
				else if (mainArg == "damage") {
					m_player->BuyDamage();
				}
				else if (mainArg == "sustain") {
					m_player->BuySustain();
				}
				else if (mainArg == "dodge") {
					m_player->BuyDodge();
				}
				else if (mainArg == "armor") {
					m_player->BuyArmor();
				}
				else {
					m_logger->WriteLine("\nI don't have that! Is there something else you're looking for? \n");
				}
			}
			else if (command == "leave") {
				srand(time(NULL));
				switch (rand() % 5) {
					case 0:
						m_logger->WriteLine("Farewell, stranger.");
						break;
					case 1:
						m_logger->WriteLine("Remember me when you have some more coin to burn!");
						break;
					case 2:
						m_logger->WriteLine("Pleasure doing business with you!");
						break;
					case 3:
						m_logger->WriteLine("Good luck, stranger.");
						break;
					case 4:
						m_logger->WriteLine("Then be on your way, stranger.");
						break;
					default:
						break;
				}
				transitionState = GAMESTATE::FLOOR;
			}
			else{
				m_logger->WriteCommandNotFound(command);
				return true;
			}
			break;

		case GAMESTATE::REST:
			// m_logger->Write("\n> ");
			if(command == "y"){
				m_logger->WriteLine("You rest and recover " + to_string(m_player->rest()) + " health.");
				m_floor->getRoom(m_floor->getCurrentRoom())->markCleared();
				transitionState = GAMESTATE::FLOOR;
			}
			else if(command == "n"){
				m_logger->WriteLine("You continue on your way.");
				transitionState = GAMESTATE::FLOOR;
			}
			else{
				m_logger->WriteLine("Invalid input. Please try again.");
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
