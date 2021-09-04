#pragma once
class UI {
public:
    UI();
    static void PrintStartMessage();
    static void PrintHelpMessage();
    static void TooManyCardsError();
    ~UI();
};