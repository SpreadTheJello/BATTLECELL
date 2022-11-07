#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <string>
#include <iostream>
#include "GAMESTATE.hpp"

class Console {
private:
    //ostream m_outStream;
    static const std::string Blue;
    static const std::string Cyan;
    static const std::string Gray;
    static const std::string Green;
    static const std::string Purple;
    static const std::string Red;
    static const std::string Reset;
    static const std::string White;
    static const std::string Yellow;

public:
    Console();
    ~Console();

    static const std::string ResetColour;
    static const std::string BadColour;
    static const std::string CommandColour;
    static const std::string ItemColour;
    static const std::string MagicColour;
    static const std::string NameColour;
    static const std::string SuccessColour;

    void Write(std::string out) const noexcept;
    void WriteLine(std::string outLine = "") const noexcept;
    void WriteCommandNotFound(std::string unknownCommand) const noexcept;
    void WriteHelp(GAMESTATE gameState) const noexcept;
    void printFile(std::string name, int milliseconds);
};

#endif // _CONSOLE_HPP_