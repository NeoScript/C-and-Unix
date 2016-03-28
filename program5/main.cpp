#include <iostream>
#include "Deck.h"

using namespace std;

string makeOutputLine(vector<Card> list, string suit){
	string s = suit+"\t";
	if(list.empty()){
		s += "-";
	}else{
		for(int i = 0;i<list.size();i++){
			s += list[i].getValue() + " ";
		}
	}

	return s;
}

//TODO: final step is to output in the right order (make them split into 4 sections like the example)
int main() {
	Hand handOne, handTwo, handThree, handFour;
	Deck deck;

	deck.dealHand(handOne);
	deck.dealHand(handTwo);
	deck.dealHand(handThree);
	deck.dealHand(handFour);

	cout << makeOutputLine(handOne.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL)<<endl;
	cout << makeOutputLine(handOne.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL)<<endl;
	cout << makeOutputLine(handOne.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL)<<endl;
	cout << makeOutputLine(handOne.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL)<<endl;

	cout << endl;

	cout << makeOutputLine(handTwo.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL)<<endl;
	cout << makeOutputLine(handTwo.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL)<<endl;
	cout << makeOutputLine(handTwo.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL)<<endl;
	cout << makeOutputLine(handTwo.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL)<<endl;
	return 0;
}