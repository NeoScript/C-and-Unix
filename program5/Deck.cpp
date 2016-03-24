//
// Created by nasir on 3/23/16.
//

#include "Deck.h"

void Deck::initDecks() {
	vector<Card> *currVector = nullptr;

	string suit;

	for(int i =0; i<SYMBOL_ARRAY->length(); i++){
		switch (i){
			case 0:
				currVector = &hearts;
				suit = HEART_SYMBOL;
				break;
			case 1:
				currVector = &diamonds;
				suit = DIAMOND_SYMBOL;
				break;
			case 2:
				currVector = &spades;
				suit = SPADE_SYMBOL;
				break;
			case 3:
				currVector = &clubs;
				suit = CLUB_SYMBOL;
				break;
			default:
				return;
		}

		for (int j = 0; j<BASE_CARD_ARRAY->length(); j++){
			currVector->push_back(Card(suit, BASE_CARD_ARRAY[j]));
		}
	}
}

void Deck::dealHand(Hand &h) {
	for (int i = 0 ; i< 13; i ++){
		int randomDeck = rand() % 4;
		vector<Card> *currVector = nullptr;
		switch (randomDeck){
			case 0:
				currVector = &hearts;
				break;
			case 1:
				currVector = &diamonds;
				break;
			case 2:
				currVector = &spades;
				break;
			case 3:
				currVector = &clubs;
				break;
			default:
				return;
		}

		unsigned long randomIndex = rand() % currVector->size();
		h.addCard(currVector->at(randomIndex));
		currVector->erase(currVector->begin() + randomIndex);
	}
}
