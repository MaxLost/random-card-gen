#pragma once
class UI {
public:
    UI();
    static void PrintStartMessage();
    static void PrintHelpMessage();
    static void TooManyCardsError();
    static void WrongCommandError();
    static void EnterDeckModeMessage();
    static void DeckModeHelpMessage();
    static void ExitDeckModeMessage();
    static void EmptyDeckMessage();
    ~UI();
};