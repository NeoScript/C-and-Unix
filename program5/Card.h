//
// Created by nasir on 3/23/16.
//

#ifndef PROGRAM5_CARD_H
#define PROGRAM5_CARD_H

#include <string>

class Card {
	using namespace std;
private:
	string suit;
	string value;
public:
	Card(string s, string val){
		this->suit = s;
		this->value = val;
	};
	string getSuit();
	string getValue();
	string toString();
};


#endif //PROGRAM5_CARD_H
