//
// Created by nasir on 3/23/16.
//

/**
 *Filename: Hand.cpp
 *Author:
 *Classes/Procedures:
 *		-Procedures:
 *			1)addCard():
 *			2)toString():
 */
#include "Hand.h"
#include <iostream>

/**
 *Class/Procedure name: addCard
 *Author:
 *Summary:
 *Arguments:
 */
void Hand::addCard(Card &c) {
	currHand.push_back(c);
}

/**
 *Class/Procedure name: toString
 *Author:
 *Summary:
 *Arguments:
 */
string Hand::toString(){
	string s;

	for(int i = 0; i<currHand.size(); i++){
		s+= " "+currHand[i].getSuit() + currHand[i].getValue();
	}

	return s;
}
