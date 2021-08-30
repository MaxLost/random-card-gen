#include <vector>
#include "Card.h"
#include "Deck.h"

Deck::Deck() {
	Node *lower_card = new Node;
	lower_card->next_node = lower_card;
	lower_card->prev_node = lower_card;
	cards_in_deck.resize(52);
	for (int i = 0; i < 52; i++) {
		cards_in_deck[i] = 0;
	}
}

void Deck::AddCard(Card &current_card) {
	if (lower_card->prev_node == lower_card->next_node) {
		if (lower_card->CheckCard() == false)
			lower_card->SetCard(current_card);
		else {
			Node* upper_card = new Node;
			upper_card->SetCard(current_card);
			upper_card->next_node = lower_card;
			upper_card->prev_node = lower_card;
			lower_card->next_node = upper_card;
			lower_card->prev_node = upper_card;
		}
	}
	else {
		Node* upper_card = new Node;
		upper_card->SetCard(current_card);
		upper_card->next_node = lower_card->next_node;
		upper_card->prev_node = lower_card;
		lower_card->next_node = upper_card;
	}
	int type, suit;
	current_card.GetProperties(type, suit);
	cards_in_deck[(type * (suit + 1)) - 2] = 1;
};

void Deck::GetCard(Node* card_ptr, Card& out) {
	card_ptr->GetCard(out);
	int type, suit;
	out.GetProperties(type, suit);
	cards_in_deck[(type * (suit + 1)) - 2] = 0;
}

void Deck::GetUpperCard(Card& out) {
	GetCard(upper_card, out);
	if (upper_card->next_node != upper_card->prev_node) {
		lower_card->next_node = upper_card->next_node;
		delete upper_card;
		upper_card = lower_card->next_node;
		upper_card->prev_node = lower_card;
	}
	else {
		upper_card->ResetCard();
	}
};

void Deck::GetLowerCard(Card& out) {
	GetCard(lower_card, out);
	if (lower_card->next_node != lower_card->prev_node) {
		upper_card->prev_node = lower_card->prev_node;
		delete lower_card;
		lower_card = upper_card->prev_node;
		lower_card->next_node = upper_card;
	}
	else {
		lower_card->ResetCard();
	}
};

bool Deck::IsCardInDeck(Card& current_card) {
	int type, suit;
	current_card.GetProperties(type, suit);
	if (cards_in_deck[(type * (suit + 1)) - 2] == 0)
		return false;
	else
		return true;
};

Deck::~Deck() {};