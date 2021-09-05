#include <iostream>
#include <string>
#include "UI.h"
#define VERSION "1.3.1"

UI::UI() {};
// Main mode messages
void UI::PrintStartMessage() {
	std::cout << std::endl;
	std::cout << "Random card generator v" << VERSION << " / For help use '-help' / For quit use '-quit'" << std::endl;
};

void UI::PrintHelpMessage() {
	std::cout << std::endl;
	std::cout << "There are commands of random card generator: " << std::endl;
	std::cout << "  -g -nodeck <amount of cards>	Generate some cards with duplicates" << std::endl;
	std::cout << "  -g -deck <amount of cards>	Generate some cards and put it in deck without duplicates" << std::endl;
};

// Error messages
void UI::TooManyCardsError() {
	std::cout << "ERROR: Too many cards to generate in deck. Maximum of cards without duplicates is 52" << std::endl;
}

void UI::WrongCommandError() {
	std::cout << "ERROR: Wrong command / For help use '-help'" << std::endl;
};

// Deck mode messages
void UI::EnterDeckModeMessage() {
	std::cout << std::endl;
	std::cout << "Now you are in DECK mode / For help print '-help'" << std::endl;
};

void UI::DeckModeHelpMessage() {
	std::cout << std::endl;
	std::cout << "There are commands of DECK mode: " << std::endl;
	std::cout << "  -getup	Take upper card from deck" << std::endl;
	std::cout << "  -getlow	Take lower card from deck" << std::endl;
	std::cout << "  -back		Return to GENERATOR mode" << std::endl;
};

void UI::ExitDeckModeMessage(){
	std::cout << std::endl;
	std::cout << "Now you are in GENERATOR mode, use default commands" << std::endl;
};

void UI::EmptyDeckMessage() {
	std::cout << "Deck is empty, generate new cards" << std::endl;
};

UI::~UI() {};