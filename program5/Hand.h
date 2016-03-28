//
// Created by nasir on 3/23/16.
//
/**
 *Filename:
 *Author:
 *Classes/Procedures:
 *		-Classes:
 *			1)Hand:
 */
#ifndef PROGRAM5_HAND_H
#define PROGRAM5_HAND_H


#include <vector>
#include "Card.h"

class Hand {
private:
	vector<Card> currHand;
public:
	void addCard(Card &c);
	string toString();
};


#endif //PROGRAM5_HAND_H
