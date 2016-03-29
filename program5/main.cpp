/**
 *Filename:
 *Author:
 *Classes/Procedures:
 *		Procedures:
 *			1)main():
 */
#include <iostream>
#include "Deck.h"

using namespace std;

/**
 *Class/Procedure name:
 *Author:
 *Summary:
 *Arguments:
 */

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


/**
 *Class/Procedure name:
 *Author:
 *Summary:
 *Arguments:
 */
//TODO: final step is to output in the right order (make them split into 4 sections like the example)

int main() {
	Hand handOne, handTwo, handThree, handFour;
	Deck deck;

	deck.dealHand(handOne);
	deck.dealHand(handTwo);
	deck.dealHand(handThree);
	deck.dealHand(handFour);

	//HAND ONE
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL).c_str());

	//HANDS TWO & THREE
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL).c_str());

	//HAND FOUR
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(Deck::HEART_SYMBOL), Deck::HEART_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(Deck::DIAMOND_SYMBOL), Deck::DIAMOND_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(Deck::CLUB_SYMBOL), Deck::CLUB_SYMBOL).c_str());
	return 0;
}
