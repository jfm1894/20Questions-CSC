#include "game.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std::string_literals;

mesa::tree<std::string>* makeDefaultTree() {
	
	mesa::tree<std::string>* yes = mesa::make_tree("Is it worth a lot of money?"s);
	mesa::tree<std::string>* no =  mesa::make_tree("Do you eat it with eggs?"s);
	mesa::tree<std::string>* root = mesa::make_tree("Is it bigger than a breadbox?"s, no, yes);
	mesa::tree<std::string>* mouse = mesa::make_tree("a mouse"s);
	mesa::tree<std::string>* spam = mesa::make_tree("spam"s);
	mesa::tree<std::string>* trash = mesa::make_tree("a bag of trash"s);
	mesa::tree<std::string>* house = mesa::make_tree("a house"s);
	mesa::tree<std::string>* prog = mesa::make_tree("a programmer"s);
	mesa::tree<std::string>* code = mesa::make_tree("Does it write code?"s, house, prog);
	no->left = mouse;
	no->right = spam;
	yes->left = trash;
	yes->right = code;
	return root;
}

bool playGame(mesa::tree<std::string>* gameTree)
{
	std::string userIn;
	std::string newVal, newQ , ans, fn;
	std::string tempVal;
	mesa::tree<std::string>* treePtr = gameTree;
	bool playAgain = false;
	while (mesa::isLeafNode(treePtr) == false)
	{
		std::cout << treePtr->value << std::endl;
		std::getline(std::cin, userIn);
		if (userIn == "no")
		{
			treePtr = treePtr->left;
		}
		else
		{
			treePtr = treePtr->right;
		}
		if (mesa::isLeafNode(treePtr) == true)
		{
			std::cout << "Is it " << treePtr->value << "?" << std::endl;
			getline(std::cin, userIn);
			if (userIn == "yes")
			{
				std::cout << "I win!" << std::endl;
			}
			else
			{
				std::cout << "OK, what were you thinking of?" << std::endl;
				getline(std::cin, newVal);
				std::cout << "Give me a question that would distinguish " << treePtr->value << " from " << newVal << std::endl;
				getline(std::cin, newQ);
				std::cout << "And would the answer to the question for " << newVal << " be yes or no?" << std::endl;
				getline(std::cin, ans);
				tempVal = treePtr->value;
				treePtr->value = newQ;
				if (ans == "yes")
				{
					treePtr->right = mesa::make_tree(newVal);
					treePtr->left = mesa::make_tree(tempVal);
				}
				else
				{
					treePtr->right = mesa::make_tree(tempVal);
					treePtr->left = mesa::make_tree(newVal);
				}
				treePtr = treePtr->right;

			}
			std::cout << "Would you like to play again?" << std::endl;
			getline(std::cin, userIn);
			if (userIn == "yes")
			{
				playAgain = true;
			}
			else
			{
				std::cout << "Would you like to save your game?" << std::endl;
				getline(std::cin, userIn);
				{
					if (userIn == "yes")
					{
						std::cout << "Please enter a filename to save your game" << std::endl;
						getline(std::cin, fn);
						writeData(gameTree, fn);
						std::cout << "Game Saved." << std::endl;
					}
				}
			}

		}

	}
	delete treePtr;
	return playAgain;
}

const void writeData(const mesa::tree<std::string>* tree, std::string fN)
{
	std::ofstream treeFile;
	treeFile.open(fN);
	treeFile << tree;
	treeFile.close();
}

mesa::tree<std::string>* readData(std::string fN)
{
	mesa::tree<std::string>* root = mesa::make_tree("root"s);
	mesa::tree<std::string>* treePtr = root;
	std::string line;
	std::ifstream treeFile;
	treeFile.open(fN);
	while (treeFile.good())
	{
		getline(treeFile, line);
		root->value = line;
	}
	treeFile.close();
	delete treePtr;
	return root;
}