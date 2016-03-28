//
// Created by nasir on 3/23/16.
//

#include "Hand.h"
#include <iostream>
#include <sstream>

void Hand::addCard(Card &c) {
	currHand.push_back(c);
}

vector<Card> Hand::getCardsOfSuit(std::string suit) {
	vector<Card> list;
	for(Card &curr:currHand){
		if(curr.getSuit()==suit){
			list.push_back(curr);
		}
	}


	sortHand(list);
	return list;
}

void Hand::sortHand(vector<Card> &list) {
	vector<Card> temp;
	string faceCards[4] = {"A","K","Q","J"};
	//adds the face cards
	for(int i=0; i<faceCards->length(); i++){
		for(int j =0; j<list.size();j++){
			if (list[j].getValue() == faceCards[i]){
				temp.push_back(list[j]);
			}
		}
	}

	//add the normal value cards
	for(int i=10; i>=2; i--){
		for(int j =0; j<list.size();j++){
			std::stringstream ss(list[j].getValue());
			int val;
			ss>>val;
			if (val == i){
				temp.push_back(list[j]);
			}
		}
	}

	list = temp;
}



