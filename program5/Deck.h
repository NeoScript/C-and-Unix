//
// Created by nasir on 3/23/16.
//

/**
 *Filename:
 *Author:
 *Classes/Procedures:
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
	static const string HEART_SYMBOL;
	static const string DIAMOND_SYMBOL;
	static const string SPADE_SYMBOL;
	static const string CLUB_SYMBOL;

	static const vector<string> SYMBOL_ARRAY;
	static const vector<string> BASE_CARD_ARRAY;

	Deck();
	void dealHand(Hand &h);
	void printDecks();
};


#endif //PROGRAM5_DECK_H
