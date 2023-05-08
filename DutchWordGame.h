#include <cassert>
#include <cstring> 
#include <chrono> 
#include <fstream>
#include <iostream>
#include <random> 
#include <sstream>
#include <string>
#include <vector>


bool userKnowsWord(std::string dutchWordIn, std::string englishWordIn, std::string userInput, bool& gameIsOn, bool& saveFile);
int tests();