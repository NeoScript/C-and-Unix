//
// Created by nasir on 3/23/16.
//

/**
 *Filename:Card.h
 *Author:
 *Classes/Procedures:
 *		Class:
 			1) Card : Contains the card's suit and value. Also has overloaded constructor and get-methods.
 */
#ifndef PROGRAM5_CARD_H
#define PROGRAM5_CARD_H

#include <string>
#include "Suit.h"

using namespace std;

class Card {
private:
	Suit *suit;
	string value;
public:
	Card(Suit *s, string val) {
		this->suit = s;
		this->value = val;
	};
	Suit* getSuit(){
		return suit;
	}
	string getValue(){
		return value;
	}
};


#endif //PROGRAM5_CARD_H
