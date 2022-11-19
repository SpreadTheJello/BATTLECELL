#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>
#include "Console.hpp"
using namespace std;

// colors
const string Console::Gray   = "\x1b[30m";
const string Console::Red    = "\x1b[31m";
const string Console::Green  = "\x1b[32m";
const string Console::Yellow = "\x1b[33m";
const string Console::Blue   = "\x1b[34m";
const string Console::Purple = "\x1b[35m";
const string Console::Cyan   = "\x1b[36m";
const string Console::White  = "\x1b[37m";
const string Console::Reset  = "\x1b[39m";

Console::Console() {
}

Console::~Console() {
}

const string Console::ResetColour   = Reset;
const string Console::BadColour     = Red;
const string Console::CommandColour = Blue;
const string Console::ItemColour    = Yellow;
const string Console::MagicColour   = Purple;
const string Console::NameColour    = Cyan;
const string Console::SuccessColour = Green;

void Console::Write(string out) const noexcept {
    cout << out;
}

void Console::WriteLine(string outLine) const noexcept {
    cout << outLine << endl;
}

void Console::WriteCommandNotFound(string unknownCommand) const noexcept {
    WriteLine("Looks like '" + unknownCommand + "' is not a valid command; try 'help'.");
}

void Console::WriteHelp(GAMESTATE gameState) const noexcept {
    WriteLine("Available commands:");
    
    switch(gameState){
        case GAMESTATE::MENU:
            WriteLine("  {new} - Start a new game.");
            break;
    
        case GAMESTATE::GAME:
            WriteLine("  {status} - Display your stats.");
            WriteLine("  {start} - Start your descent into the dungeon.");
            break;
            
        case GAMESTATE::FLOOR:
            WriteLine("  {display} - View the current floor.");
            WriteLine("  {go} {north}{east}{south}{west} - Move to a different room.");
            WriteLine("  {status} - Display your and (if applicable) enemy's stats.");
            break;
        
        case GAMESTATE::COMBAT:
            WriteLine("  {attack} - Attack a monster in the room.");
            WriteLine("  {status} - Display your and (if applicable) enemy's stats.");
            WriteLine("  {flee} - Attempt to run away from the monster.");
            WriteLine("  {display} - View the current floor.");
            break;

        case GAMESTATE::SHOP:
            WriteLine("  {view} - See what the shopkeeper is selling.");
            WriteLine("  {buy} {stat} - Purchase a stat improvement from the shop.");
            WriteLine("  {leave} - leave the shop");
            WriteLine("  {status} - Display your stats.");
            break;

        default:
            break;
    }
    WriteLine("  {help} - Display this help message.");
    WriteLine("  {exit} - Exit the game.");
}

// loop through file and print each line with a delay
void Console::printFile(string name, int milliseconds) {
    ifstream file("../ascii/" + name + ".txt");
    string line;
    while(getline(file, line)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        WriteLine(line);
    }
}
