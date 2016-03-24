//
// Created by nasir on 3/23/16.
//

#ifndef PROGRAM5_CARD_H
#define PROGRAM5_CARD_H

#include <string>
using namespace std;

class Card {
private:
	string suit;
	string value;
public:
	Card(string s, string val){
		this->suit = s;
		this->value = val;
	};
	string getSuit(){
		return this->suit;
	}
	string getValue(){
		return this->value;
	}
};


#endif //PROGRAM5_CARD_H
