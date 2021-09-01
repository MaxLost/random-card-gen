#include <iostream>
#include <string>
#include "UI.h"

UI::UI() {};

void UI::PrintStartMessage() {
	std::cout << std::endl;
	std::cout << "Random card generator v1.2.1 / For help print '-h' / For quit print '-q'";
	std::cout << std::endl;
};

void UI::PrintHelpMessage() {

};

UI::~UI() {};