#include <iostream>
#include <string>
#include "UI.h"
#include "Deck.h"
#include "RandomCardGenerator.h"
#include "Card.h"

int main(void){
    using namespace std;
    string input;
    UI::PrintStartMessage();
    while (true) {
        cin >> input;
        if (input == "-help") {
            UI::PrintHelpMessage();
        }
        else if (input == "-quit") {
            exit(0);
        }
        else if (input == "-g") {
            int n;
            string form;
            cin >> form;
            cin >> n;
            if (form == "-nodeck") {
                RandomCardGenerator* Generator = new RandomCardGenerator;
                for (int i = 0; i < n; i++) {
                    (*Generator).GenerateCards();
                }
                delete Generator;
            }
            else if (form == "-deck") {
                RandomCardGenerator* Generator = new RandomCardGenerator;
                Deck* CurrentDeck = new Deck;
                if (n > 52) {
                    UI::TooManyCardsError();
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
                                UI::WrongCommandError();
                            
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
        }
        else {
            UI::WrongCommandError();
        }
    }
    return 0;
}