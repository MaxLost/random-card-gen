#include <iostream>
#include <string>
#include "UI.h"

UI::UI() {};

void UI::PrintStartMessage() {
	std::cout << std::endl;
	std::cout << "Random card generator v1.2.1 / For help print '-help' / For quit print '-quit'";
	std::cout << std::endl;
};

void UI::PrintHelpMessage() {
	std::cout << std::endl;
	std::cout << "There are commands of random card generator: ";
	std::cout << std::endl;
	std::cout << "  -g -nodeck <amount of cards>	Generate some cards with duplicates";
	std::cout << std::endl;
	std::cout << "  -g -deck <amount of cards>	Generate some cards and put it in deck without duplicates";
	std::cout << std::endl;
};

UI::~UI() {};