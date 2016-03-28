//
// Created by nasir on 3/23/16.
//

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
	vector<Card> getCardsOfSuit(std::string suit);
};


#endif //PROGRAM5_HAND_H
