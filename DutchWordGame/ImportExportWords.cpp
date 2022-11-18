#include "DutchWordGame.h"

std::vector<std::string> importWords()
{
    // Store the contents into a vector of strings
    std::vector<std::string> outputs;

    std::cout << "Reading from CurrentSave.txt ...\n";

    // Create the file object (input)
    std::ifstream infile("CurrentSave.txt");

    // Temporary buffer
    std::string temp;

    // Get the input from the input file until EOF
    while (std::getline(infile, temp)) {
        // Add to the list of output strings
        outputs.push_back(temp);
    }
    infile.close();

    return outputs;
}

void copyDefaultWords()
{
    std::ifstream infile("CurrentSave.txt");
    if (infile.peek() == std::ifstream::traits_type::eof())
    {

        std::ifstream source("DutchWordsDefault.txt", std::ios::binary);
        std::ofstream dest("CurrentSave.txt", std::ios::binary);

        // file size
        source.seekg(0, std::ios::end);
        std::ifstream::pos_type size = source.tellg();
        source.seekg(0);
        // allocate memory for buffer
        char* buffer = new char[size];

        // copy file    
        source.read(buffer, size);
        dest.write(buffer, size);

        // clean up
        delete[] buffer;
        source.close();
        dest.close();
    }
    infile.close();
}

void clearWords()
{
    std::ofstream ofs;
    ofs.open("CurrentSave.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
