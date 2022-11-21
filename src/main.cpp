#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

#include "Game.hpp"

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


int main(int argc, char ** args)
{
    Console * console = new Console();
    Game * game = new Game();
    string lineIn;
    
    system("clear");
    console->WriteLine("\n\n\n\n\n\n");
    console->printFile("title", 200);
    console->WriteLine("\t\t\t\tWelcome to Battlecell!\n");
    console->WriteLine("Menu: From here, you can start a {new} game, or {exit}! At any time, {help} will tell you the available commands.");
    console->Write("\n> ");
    
    // begins game loop
    while (getline(cin, lineIn)) {
        if (lineIn.size() > 0) {
            vector<string> input = split(lineIn, ' ');
            string command = input.at(0);
            string mainArg;
            string fullArg;
            if (input.size() > 1) {
                mainArg = input.at(1);
                fullArg = lineIn.substr(command.length() + 1, string::npos);
            }

            // if ProcessCommand returns false, then quit the game
            if (!game->ProcessCommand(command, mainArg, fullArg)) {
                break;
            }
        }

        // begin the next line to prompt user input
        console->Write("\n> ");
    }

    return 0;
}
