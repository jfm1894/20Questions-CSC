// 20q.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "tree.h"
#include <iostream>
#include "game.h"

using namespace mesa;

int main(int argc, char **argv)
{
    bool fromFile = false;
    std::string fileName;
    tree<std::string>* root;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            std::cout << "Usage: ./20q [-h] [-f file_name]" << std::endl;
            std::cout << "\nOptions:\n\t-h\tShow this text.\n\t-f\tLoad a game tree from a file" << std::endl;
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            fromFile = true;
            fileName = argv[i + 1];
        }
    }

    if (fromFile == true)
    {
        root = readData(fileName);
    }
    else
    {
        root = makeDefaultTree();
    }
    while (playGame(root) == true)
    {

    }
    delete root;
    std::cout << "Goodbye!" << std::endl;
}

