/**
 *Filename: main.cpp
 *Author: Nasir
 *Classes/Procedures:
 *		Procedures:
 *			1)main(): the main function...
 */
#include <iostream>
#include "Deck.h"

using namespace std;

/**
 *Class/Procedure name: makeOutputLine
 *Author: Nasir
 *Summary: Creates the correct output string for the cards of a given suit within the list
 *Arguments: list of cards of suit x, suit x
 */

string makeOutputLine(vector<Card> list, Suit *suit){
	string s = suit->getString()+"\t";
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
 *Class/Procedure name: main
 *Author: Nasir
 *Summary: runs the whole program
 *Arguments: none
 */

int main() {
	Hand handOne, handTwo, handThree, handFour;
	Deck deck;

	deck.dealHand(handOne);
	deck.dealHand(handTwo);
	deck.dealHand(handThree);
	deck.dealHand(handFour);

	//HAND ONE
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(new Spade), new Spade).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(new Heart), new Heart).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(new Diamond), new Diamond).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handOne.getCardsOfSuit(new Club), new Club).c_str());

	//HANDS TWO & THREE
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(new Spade), new Spade).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(new Spade), new Spade).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(new Heart), new Heart).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(new Heart), new Heart).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(new Diamond), new Diamond).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(new Diamond), new Diamond).c_str());
	printf("%-20s %20s %-20s\n", makeOutputLine(handTwo.getCardsOfSuit(new Club), new Club).c_str(), "", makeOutputLine(handThree.getCardsOfSuit(new Club), new Club).c_str());

	//HAND FOUR
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(Deck::SPADE_SYMBOL), Deck::SPADE_SYMBOL).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(new Heart), new Heart).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(new Diamond), new Diamond).c_str());
	printf("%-20s %-20s\n", "", makeOutputLine(handFour.getCardsOfSuit(new Club), new Club).c_str());
	return 0;
}
