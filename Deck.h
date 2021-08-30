#pragma once
#include <vector>
#include "Card.h"

class Deck {
private:
	struct Node{
		private:
			Card *card = nullptr;
		public:
			Node* prev_node = nullptr;
			Node* next_node = nullptr;
			void SetCard(Card& input) {
				card = &input;
			}
			void GetCard(Card& output) {
				output = *card;
			}
			bool CheckCard() {
				if (card == nullptr)
					return false;
				else
					return true;
			}
			void ResetCard() {
				card = nullptr;
			}
	};
	std::vector <int> cards_in_deck;
public:
	Node* upper_card = nullptr;
	Node* lower_card = nullptr;
	Deck();
	void AddCard(Card &current_card);
	void GetCard(Node* card_ptr, Card& out);
	void GetUpperCard(Card &out);
	void GetLowerCard(Card &out);
	bool IsCardInDeck(Card& current_card);
	~Deck();
};