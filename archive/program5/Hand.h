//
// Created by nasir on 3/23/16.
//
/**
 *Filename: Hand.h
 *Author: Nasir
 *Classes/Procedures:
 *	sortHand() -> sorts the hand for output in correct way
 *	addCard() -> adds given card to Hand
 *	getCardsOfSuit() -> returns vector of cards with specific suit
 */
#ifndef PROGRAM5_HAND_H
#define PROGRAM5_HAND_H


#include <vector>
#include "Card.h"

class Hand {
private:
	vector<Card> currHand;
	void sortHand(vector<Card> &list);
public:
	void addCard(Card &c);
	vector<Card> getCardsOfSuit(Suit *suit);
};


#endif //PROGRAM5_HAND_H
