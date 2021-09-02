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
                    (*Generator).GenerateRandomCard();
                }
                delete Generator;
            }
            else if (form == "-deck") {
                RandomCardGenerator* Generator = new RandomCardGenerator;
                Deck* CurrentDeck = new Deck;
                if (n > 36)
                cout << "ERROR:  Temporarly unavailable function" << endl;
            }
        }
    }
    system("pause");
    return 0;
}