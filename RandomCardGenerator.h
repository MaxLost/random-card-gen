#pragma once
#include <vector>
#include <string>
#include <random>
#include "Card.h"
#include "Deck.h"
class RandomCardGenerator {
private:
	std::mt19937 rng;
	void InitTypesSet();
	enum Suits {
		Spades,
		Clubs,
		Hearts,
		Diamonds
	};
	std::vector <int> type;
public:
	RandomCardGenerator();
	void ShowCard(Card& current_card);
	void GenerateRandomCard(Card& out);
	void GenerateCardInDeck(Deck& CurrentDeck);
	void GenerateCards();
	~RandomCardGenerator();
};