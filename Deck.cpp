#include <vector>
#include "Card.h"
#include "Deck.h"

Deck::Deck() {
	upper_card = new Node;
	cards_in_deck.resize(52);
	for (int i = 0; i < 52; i++) {
		cards_in_deck[i] = 0;
	}
}

void Deck::AddCard(Card &current_card) {
	if (upper_card->CheckCard() == false) {
		upper_card->SetCard(current_card);
	}
	else {
		lower_card = upper_card;
		upper_card = new Node;
		upper_card->next_node = lower_card;
		lower_card->prev_node = upper_card;
		upper_card->SetCard(current_card);
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
	if (upper_card->next_node != nullptr) {
		upper_card = upper_card->next_node;
		delete upper_card->prev_node;
		upper_card->prev_node = nullptr;
	}
	else {
		upper_card->ResetCard();
	}
};

void Deck::GetLowerCard(Card& out) {
	Node* lower_card = upper_card;
	while (lower_card->next_node != nullptr)
		lower_card = lower_card->next_node;
	GetCard(lower_card, out);
	if (lower_card->prev_node != nullptr) {
		lower_card = lower_card->prev_node;
		delete lower_card->next_node;
		lower_card->next_node = nullptr;
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