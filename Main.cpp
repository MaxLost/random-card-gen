#include <iostream>
#include <string>
#include "UI.h"
#include "RandomCardGenerator.h"
#include "Card.h"

int main(void){
    using namespace std;
    string input;
    while (true) {
        if (input != "-h")
            UI::PrintStartMessage();
        cin >> input;
        if (input == "-h") {
            UI::PrintHelpMessage();
        }
        else if (input == "-q") {
            exit(0);
        }
        else if (input == "-g") {
            int n;
            cin >> n;
            RandomCardGenerator* Generator = new RandomCardGenerator;
            for (int i = 0; i < n; i++) {
                (*Generator).GenerateRandomCard();
            }
            delete Generator;
        }
    }
    system("pause");
    return 0;
}