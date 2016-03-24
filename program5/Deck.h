//
// Created by nasir on 3/23/16.
//

#ifndef PROGRAM5_DECK_H
#define PROGRAM5_DECK_H

#include <vector>
#include "Card.h"
#include "Hand.h"

using namespace std;
class Deck {
private:
	const string BASE_CARD_ARRAY[13] = {"2", "3", "4", "5", "6",
	                                  "7", "8", "9", "10",
	                                  "J", "Q", "K", "A"};

	const string SYMBOL_ARRAY[4] = {HEART_SYMBOL, DIAMOND_SYMBOL,
	                               SPADE_SYMBOL, CLUB_SYMBOL};

	const string HEART_SYMBOL = "♥";
	const string DIAMOND_SYMBOL = "♦";
	const string SPADE_SYMBOL = "♠";
	const string CLUB_SYMBOL = "♣";

	vector<Card> hearts;
	vector<Card> diamonds;
	vector<Card> spades;
	vector<Card> clubs;

	void initDecks();
	void dealHand(Hand &h);
public:
	Deck(){
		initDecks();
	}
};


#endif //PROGRAM5_DECK_H