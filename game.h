#pragma once
#include "tree.h"



mesa::tree<std::string>* makeDefaultTree();
mesa::tree<std::string>* readData(std::string fN);
const void writeData(const mesa::tree<std::string>* tree, std::string fN);
bool playGame(mesa::tree<std::string>* gameTree);

