#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <string>
#include <iostream>
using namespace std;

class Console {
private:
    //ostream m_outStream;
    static const string Blue;
    static const string Cyan;
    static const string Gray;
    static const string Green;
    static const string Purple;
    static const string Red;
    static const string Reset;
    static const string White;
    static const string Yellow;

public:
    Console();
    ~Console();

    static const string ResetColour;
    static const string BadColour;
    static const string CommandColour;
    static const string ItemColour;
    static const string MagicColour;
    static const string NameColour;
    static const string SuccessColour;

    void Write(string out) const noexcept;
    void WriteLine(string outLine = "") const noexcept;
    void WriteCommandNotFound(string unknownCommand) const noexcept;
    void printFile(string name, int milliseconds) const noexcept;
};

#endif // _CONSOLE_HPP_