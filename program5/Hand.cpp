//
// Created by nasir on 3/23/16.
//

#include "Hand.h"
#include <iostream>

void Hand::addCard(Card &c) {
	currHand.push_back(c);
}

string Hand::toString(){
	string s;

	for(int i = 0; i<currHand.size(); i++){
		s+= " "+currHand[i].getSuit() + currHand[i].getValue();
	}

	return s;
}