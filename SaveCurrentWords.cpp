#include "DutchWordGame.h"

// Unused, it is easier to just copy the words and pop them as they're removed than add them like this

void save(std::string word)
{
    std::ofstream outFile("CurrentGame.txt", std::ios::app); // changes it to append mode and adds text to end of file
    if (outFile.is_open())
    {
        
        // Process save
        outFile << word << std::endl;
        outFile.close();
    }
    else std::cout << "Unable to open file";
}