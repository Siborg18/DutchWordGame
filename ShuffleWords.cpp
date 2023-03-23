#include "DutchWordGame.h"
#include <random> 

std::mt19937 randomSeed()
{
    std::mt19937 mt{ std::random_device{}() };
    return mt;
}

std::vector<std::string> randomWords()
{
    std::random_device rng;
    //auto rng = std::default_random_engine{ randomSeed() };

    std::vector<std::string> words{ importWords() };

    std::shuffle(std::begin(words), std::end(words), rng);

    return words;
}