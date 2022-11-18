#include "DutchWordGame.h"


int main() {
   
    copyDefaultWords();
    std::vector<std::string> words{randomWords()};

    for (int i{}; i < 50; i++)
    {
        words.pop_back();
    }

    clearWords();
    for (const auto& word : words)
        save(word);

    //Use a range-based for loop to iterate through the output vector
    for (const auto& word : words)
        std::cout << word << std::endl;

    //std::string currentWord{ words[words.size() - 1] };
    //std::cout << currentWord << std::endl;

    return 0;
}