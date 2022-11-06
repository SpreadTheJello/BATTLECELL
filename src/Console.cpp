#include "Console.hpp"
#include <iomanip>

const std::string Console::Gray   = "\x1b[30m";
const std::string Console::Red    = "\x1b[31m";
const std::string Console::Green  = "\x1b[32m";
const std::string Console::Yellow = "\x1b[33m";
const std::string Console::Blue   = "\x1b[34m";
const std::string Console::Purple = "\x1b[35m";
const std::string Console::Cyan   = "\x1b[36m";
const std::string Console::White  = "\x1b[37m";
const std::string Console::Reset  = "\x1b[39m";

Console::Console() {
}

Console::~Console() {
}

const std::string Console::ResetColour   = Reset;
const std::string Console::BadColour     = Red;
const std::string Console::CommandColour = Blue;
const std::string Console::ItemColour    = Yellow;
const std::string Console::MagicColour   = Purple;
const std::string Console::NameColour    = Cyan;
const std::string Console::SuccessColour = Green;

void Console::Write(std::string out) const noexcept {
    std::cout << out;
}

void Console::WriteLine(std::string outLine) const noexcept {
    std::cout << outLine << std::endl;
}

void Console::WriteCommandNotFound(std::string unknownCommand) const noexcept {
    WriteLine("Looks like '" + unknownCommand + "' is not a valid command; try 'help'.");
}
