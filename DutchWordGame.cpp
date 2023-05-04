#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring> 
#include <vector>

bool g_gameIsOn {true}; // I need to remove this global variable, I'll need to redo the user input
                        // I'll need to make the userInput usable for all functions

std::pair<std::string, std::string> readLinesFromFileAsPair(const std::string& line)
{
  std::cout << "Running readLinesFromFileAsPair...";
  std::istringstream iss(line);
  std::string firstPart, secondPart;
  std::getline(iss, firstPart, ',');
  std::getline(iss, secondPart);
  return std::make_pair(firstPart, secondPart);
}

std::vector<std::string> readLinesFromFile(const std::string& file_path) {
    std::cout << "Running readLinesFromFile" << std::endl;
    std::ifstream file(file_path);
    std::string line;
    std::vector<std::string> wordListOut{};
    while (std::getline(file, line)){
    // Do something with the line
    // For example, print it to the console:
    wordListOut.push_back(line);
    //std::cout << line << std::endl;
  }
  file.close();
  return wordListOut;
}

void writeVectorToFile(const std::vector<std::string>& wordListIn, const std::string& filename) {
    std::cout << "Running writeVectorToFile" << std::endl;
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& element : wordListIn) {
            file << element << " " << std::endl;
        }
        file.close();
        std::cout << "Vector elements written to file successfully." << std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

int getRandomNumber(int lowerLimit, int upperLimit)
{
  // random number gen to grab random word from word list
  return 0;
}

bool userKnowsWord(std::string dutchWordIn, std::string englishWordIn)
{
  std::cout << "Do you know the word: (y or n) " << dutchWordIn << std::endl;
  char x {};
  std::cin >> x;

  if (x == 'y' || x == 'Y')
  {
    std::cout << "Player knows the word: " << dutchWordIn << " means " << englishWordIn << std::endl;
    return true;
  }
  else if (x == 'n' || x == 'N')
  {
    std::cout << "Player does not know the word: " << dutchWordIn << std::endl;
    std::cout << "Translation:  " << dutchWordIn << " means " << englishWordIn << std::endl;
    return false;
  }
  if (x == 'q' || 'e')
  {
    g_gameIsOn = false;
    return false;
  }
  else
  {
    std::cout << "Unknown response, try again: " << std::endl;
    return false;
    // will need to make this ask for the same word again, will probably need a while loop
  }
}

int main ()
{
    std::vector<std::string> wordList {};
    int n {0};
    wordList = readLinesFromFile("DutchWordsDefault.txt");
    while (g_gameIsOn)
    {
    std::cout << "This is the number of elements in wordlist " << wordList.size() << std::endl;
    std::pair<std::string, std::string> currentWord {};
    currentWord = readLinesFromFileAsPair(wordList[n]);
    std::cout << "Current word first part: " << currentWord.first << std::endl; 
    std::cout << "Current word second part: " << currentWord.second << std::endl;
    if(userKnowsWord(currentWord.first, currentWord.second))
    {
      wordList.erase(wordList.begin() + n);
    }
    }
    

/*     for (int i{0}; i < wordList.size(); i++)
    {
      std::cout << wordList[i] << std::endl;
    } */


    writeVectorToFile(wordList, "SavedWords.txt");
    return 0;
}