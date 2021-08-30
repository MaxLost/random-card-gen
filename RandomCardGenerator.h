#pragma once
#include <vector>
#include <string>
#include <random>
#include "Card.h"
class RandomCardGenerator {
private:
	std::mt19937 rng;
	void InitPropertiesSets(std::vector <int>& type, std::vector <std::string>& suits);
	void ShowCard(Card& current_card, std::vector <std::string>& suits);
public:
	RandomCardGenerator();
	void GenerateRandomCard();
	~RandomCardGenerator();
};