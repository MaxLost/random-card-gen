#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include "RandomCardGenerator.h"
#include "Card.h"
#include "Deck.h"

RandomCardGenerator::RandomCardGenerator() {
    InitTypesSet();
};

void RandomCardGenerator::InitTypesSet() {
    int n = 13;
    type.resize(n);
    // Values in array: 2-10 — numbers; 11 — Jack; 12 — Queen; 13 — King; 14 — Ace
    for (int i = 0; i < n; i++) // Initializing types of cards;
        type[i] = i + 2;
};

void RandomCardGenerator::ShowCard(Card& current_card) {
    int card_type, card_suit;
    current_card.GetProperties(card_type, card_suit); // Getting properties of current card

    if (card_type == -1 || card_suit == -1) { // Checking correct initialization of current card
        std::cout << "Card initialization error" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (card_suit == Spades)
        std::cout << "Spades" << ' ';
    else if (card_suit == Clubs)
        std::cout << "Clubs" << ' ';
    else if (card_suit == Hearts)
        std::cout << "Hearts" << ' ';
    else if (card_suit == Diamonds)
        std::cout << "Diamonds" << ' ';

    if (card_type <= 10) {  // Checking only upper border because "Card" object can't contain wrong values
        std::cout << card_type << std::endl;
    }
    else if (card_type == 11)
        std::cout << "Jack" << std::endl;
    else if (card_type == 12)
        std::cout << "Queen" << std::endl;
    else if (card_type == 13)
        std::cout << "King" << std::endl;
    else if (card_type == 14)
        std::cout << "Ace" << std::endl;
}

void RandomCardGenerator::GenerateRandomCard(Card &current_card) {  
    std::random_device rd;
    std::mt19937 rng;
    rng.seed(rd() + time(0));
    std::uniform_int_distribution<unsigned> distribution(1, 10e9);
    unsigned x = distribution(rng);

    (current_card).Card::SetProperties(type[x % 13], x % 4);
};

void RandomCardGenerator::GenerateCardInDeck(Deck &CurrentDeck) {
    Card* current_card = new Card;
    RandomCardGenerator::GenerateRandomCard(*current_card);
    while (CurrentDeck.IsCardInDeck(*current_card) == true) {
        delete current_card;
        current_card = new Card;
        RandomCardGenerator::GenerateRandomCard(*current_card);
    }
    CurrentDeck.AddCard(*current_card);
};

void RandomCardGenerator::GenerateCards() {
    Card* current_card = new Card;
    RandomCardGenerator::GenerateRandomCard(*current_card);
    RandomCardGenerator::ShowCard(*current_card);
    delete current_card;
};

RandomCardGenerator::~RandomCardGenerator() {};