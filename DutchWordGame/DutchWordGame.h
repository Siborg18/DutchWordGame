#pragma once

#include <iostream>
#include <string>
#include <vector> // For std::vector
#include <fstream> // For std::ifstream and std::ofstream
#include <random> 

std::vector<std::string> importWords();
std::vector<std::string> randomWords();
void save(std::string word);
void copyDefaultWords();
void clearWords();