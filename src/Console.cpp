#include "Console.hpp"
#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>
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

// loop through file and print each line with a delay
void Console::printFile(string name, int milliseconds) const noexcept {
    ifstream file("../ascii/" + name + ".txt");
    string line;
    while(getline(file, line)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        WriteLine(line);
    }
}
