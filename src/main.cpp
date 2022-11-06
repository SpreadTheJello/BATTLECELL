#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

#include "Game.hpp"

int main(int argc, char ** args)
{
    Console * console = new Console();
    Game * game = new Game();

    // begins game loop
    string lineIn;
    console->Write("\n\n\n\n\n\n\n\n\n");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine(" ▄▄▄▄    ▄▄▄     ▄▄▄█████▓▄▄▄█████▓ ██▓    ▓█████  ▄████▄  ▓█████  ██▓     ██▓    ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("▓█████▄ ▒████▄   ▓  ██▒ ▓▒▓  ██▒ ▓▒▓██▒    ▓█   ▀ ▒██▀ ▀█  ▓█   ▀ ▓██▒    ▓██▒    ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("▒██▒ ▄██▒██  ▀█▄ ▒ ▓██░ ▒░▒ ▓██░ ▒░▒██░    ▒███   ▒▓█    ▄ ▒███   ▒██░    ▒██░    ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("▒██░█▀  ░██▄▄▄▄██░ ▓██▓ ░ ░ ▓██▓ ░ ▒██░    ▒▓█  ▄ ▒▓▓▄ ▄██▒▒▓█  ▄ ▒██░    ▒██░    ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("░▓█  ▀█▓ ▓█   ▓██▒ ▒██▒ ░   ▒██▒ ░ ░██████▒░▒████▒▒ ▓███▀ ░░▒████▒░██████▒░██████▒");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("░▒▓███▀▒ ▒▒   ▓▒█░ ▒ ░░     ▒ ░░   ░ ▒░▓  ░░░ ▒░ ░░ ░▒ ▒  ░░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("▒░▒   ░   ▒   ▒▒ ░   ░        ░    ░ ░ ▒  ░ ░ ░  ░  ░  ▒    ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine(" ░    ░   ░   ▒    ░        ░        ░ ░      ░   ░           ░     ░ ░     ░ ░   ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine(" ░            ░  ░                     ░  ░   ░  ░░ ░         ░  ░    ░  ░    ░  ░");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("      ░                                           ░                               ");
    this_thread::sleep_for(chrono::milliseconds(200));
    console->WriteLine("\t\t\t\tWelcome to Battlecell!\n");
    console->WriteLine("Menu: From here, you can start a {new} game, or {exit}! At any time, {help} will tell you the available commands.");
    console->Write("\n> ");
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
