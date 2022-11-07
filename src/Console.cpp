#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>
#include "Console.hpp"
using namespace std;

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
            WriteLine("  {exit} - Exit the game.");
            break;
    
        case GAMESTATE::GAME:
            WriteLine("  {help} - Display this help message.");
            WriteLine("  {exit} - Exit the game.");
            WriteLine("  {loot} - Loot available items in room.");
            WriteLine("  {go} - Move to a different room.");
            WriteLine("  {inventory} - Display your inventory.");
            WriteLine("  {equip} - Equip an item from your inventory.");
            WriteLine("  {unequip} - Unequip an item from your inventory.");
            WriteLine("  {stats} - Display your stats.");
            WriteLine("  {attack} - Attack a monster in the room.");
        default:
            break;
    }
    WriteLine("  {help} - Display this help message.");
    WriteLine("  {exit} - Exit the game.");
}

// loop through file and print each line with a delay
void Console::printFile(string name, int milliseconds) const noexcept {
    ifstream file("../ascii/" + name + ".txt");
    string line;
    while(getline(file, line)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        WriteLine(line);
    }
}
