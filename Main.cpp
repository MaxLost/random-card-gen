#include <iostream>
#include <string>
#include <regex>
#include "UI.h"
#include "Deck.h"
#include "RandomCardGenerator.h"
#include "Card.h"

int main(void){
    using namespace std;
    string input;
    UI::PrintStartMessage();
    while (true) {
        try {
            cin >> input;
            if (input == "-help") {
                UI::PrintHelpMessage();
            }
            else if (input == "-quit") {
                exit(0);
            }
            else if (input == "-g") {
                string num;
                string form;
                cin >> form;
                if (form == "-nodeck") {
                    cin >> num;
                    for (int i = 0; i < num.size(); i++) {
                        if (isdigit(num[i]) == false)
                            throw exception();
                    }
                    int n = stoi(num);
                    RandomCardGenerator* Generator = new RandomCardGenerator;
                    for (int i = 0; i < n; i++) {
                        (*Generator).GenerateCards();
                    }
                    delete Generator;
                }
                else if (form == "-deck") {
                    cin >> num;
                    for (int i = 0; i < num.size(); i++) {
                        if (isdigit(num[i]) == false)
                            throw exception();
                    }
                    int n = stoi(num);
                    RandomCardGenerator* Generator = new RandomCardGenerator;
                    Deck* CurrentDeck = new Deck;
                    if (n > 52) {
                        throw exception("TooManyCards");
                    }
                    else {
                        for (int i = 0; i < n; i++) {
                            (*Generator).GenerateCardInDeck(*CurrentDeck);
                        }
                        UI::EnterDeckModeMessage();
                        while (true) {
                            cin >> input;
                            if (input == "-help")
                                UI::DeckModeHelpMessage();
                            else if (input == "-back") {
                                UI::ExitDeckModeMessage();
                                break;
                            }
                            else {
                                Card* current_card = new Card;

                                if (input == "-getup")
                                    CurrentDeck->GetUpperCard(*current_card);
                                else if (input == "-getlow")
                                    CurrentDeck->GetLowerCard(*current_card);
                                else
                                    throw exception("UnkownCommand");

                                Generator->ShowCard(*current_card);
                                if (CurrentDeck->upper_card->CheckCard() == false) {
                                    UI::EmptyDeckMessage();
                                    UI::ExitDeckModeMessage();
                                    break;
                                }
                            }
                        }
                    }

                }
                else {
                    throw exception("UnkownCommand");
                }
            }
            else {
                throw exception("UnknownCommand");
            }
        }
        catch (exception &error) {
            string error_type = error.what();
            if (error_type == "UnknownCommand")
                UI::UnknownCommandError();
            else if (error_type == "TooManyCards")
                UI::TooManyCardsError();
            else
                UI::UndefinedError();
        }
    }
    return 0;
}