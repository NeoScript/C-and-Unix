//
// Created by nasir on 3/23/16.
//

/**
 *Filename: Deck.h
 *Author: Nasir
 *Classes/Procedures:
 *	Deck() -> constructor
 * 	initDecks() -> adds the decks to the appropriate vector of cards
 * 	dealHand() -> deals 13 cards to given hand
 */
#ifndef PROGRAM5_DECK_H
#define PROGRAM5_DECK_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Hand.h"

using namespace std;
class Deck {
private:
	vector<Card> hearts;
	vector<Card> diamonds;
	vector<Card> spades;
	vector<Card> clubs;

	void initDecks();
	template <typename T> void remove_at(std::vector<T>& v, typename std::vector<T>::size_type n);
public:
	static Suit * HEART_SYMBOL;
	static Diamond *DIAMOND_SYMBOL;
	static Spade * SPADE_SYMBOL;
	static Club * CLUB_SYMBOL;

	static vector<Suit*> SYMBOL_ARRAY;
	static const vector<string> BASE_CARD_ARRAY;

	Deck();
	void dealHand(Hand &h);
};


#endif //PROGRAM5_DECK_H
