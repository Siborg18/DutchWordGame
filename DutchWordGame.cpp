#include <cassert>
#include <cstring> 
#include <chrono> 
#include <fstream>
#include <iostream>
#include <random> 
#include <sstream>
#include <string>
#include <vector>

// bool g_gameIsOn {true}; // I need to remove this global variable, I'll need to redo the user input
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

std::mt19937 randomSeed()
{
	std::mt19937 seed{ std::random_device{}() };

  return seed;
}

int getRandomNumber(int upperLimit, std::mt19937 seed)
{
  std::uniform_int_distribution<> numberGenerator{ 0, upperLimit };
  int randomNumber = numberGenerator(seed);
  // random number gen to grab random word from word list
  return randomNumber;
}

void emptySaveFile()
{
  std::ofstream ofs;
  ofs.open("SavedWords.txt", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
}

bool userKnowsWord(std::string dutchWordIn, std::string englishWordIn, std::string userInput, bool& gameIsOn, bool& saveFile)
{
  char c{};
  if(userInput.size() == 1)
  {
    c = userInput.at(0);
  }
  else
  {
  for (char& c : userInput) {
        c = std::tolower(c);
    }
  }
  if (userInput == "yes" || c == 'y')
  {
    std::cout << "Player knows the word: " << dutchWordIn << " means " << englishWordIn << std::endl;
    return true;
  }
  else if (userInput == "no" || c == 'n')
  {
    std::cout << "Player does not know the word: " << dutchWordIn << std::endl;
    std::cout << "Translation:  " << dutchWordIn << " means " << englishWordIn << std::endl;
    return false;
  }
  if (userInput == "quit" || userInput == "exit" || c == 'q')
  {
    gameIsOn = false;
    return false;
  }
  if(userInput == "reset" || c == 'r')
  {
    emptySaveFile();
    saveFile = false;
    gameIsOn = false;
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
  std::mt19937 initSeed{randomSeed()};
  std::vector<std::string> wordList {};
  wordList = readLinesFromFile("SavedWords.txt");
  int n {0};
  std::string userInput {};
  bool gameIsOn {true};
  bool saveFile {true};
  if (wordList.size() < 1)
  {
    std::cout << "File is empty importing default Dutch words" << std::endl;
    wordList = readLinesFromFile("DutchWordsDefault.txt");
  }    
  while (gameIsOn)
  {
  n = getRandomNumber(wordList.size(), initSeed);
  std::cout << "This is the number of elements in wordlist " << wordList.size() << std::endl;
  std::pair<std::string, std::string> currentWord {};
  currentWord = readLinesFromFileAsPair(wordList[n]);
  std::cout << "Do you know the word: (yes or no)(reset to restart game or exit to quit) " << currentWord.first << std::endl;
  std::cin >> userInput;
  std::cout << "Current word first part: " << currentWord.first << std::endl; 
  std::cout << "Current word second part: " << currentWord.second << std::endl;
  if(userKnowsWord(currentWord.first, currentWord.second, userInput, gameIsOn, saveFile))
  {
    wordList.erase(wordList.begin() + n);
  }
  }
    

/*     for (int i{0}; i < wordList.size(); i++)
    {
      std::cout << wordList[i] << std::endl;
    } */

  if (saveFile)
  {
    writeVectorToFile(wordList, "SavedWords.txt");
  }
    return 0;
}