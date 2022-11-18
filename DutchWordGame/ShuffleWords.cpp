#include "DutchWordGame.h"

std::mt19937 randomSeed()
{
    std::mt19937 mt{ std::random_device{}() };
    return mt;
}

std::vector<std::string> randomWords()
{
    auto rng = std::default_random_engine{ randomSeed() };

    std::vector<std::string> words{ importWords() };

    std::shuffle(std::begin(words), std::end(words), rng);

    return words;
}