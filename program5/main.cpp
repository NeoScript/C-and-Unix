#include <iostream>
#include "Deck.h"

using namespace std;

int main() {
	Hand handOne, handTwo, handThree, handFour;
	Deck deck;

	deck.printDecks();
	deck.dealHand(handOne);
	deck.dealHand(handTwo);
	deck.dealHand(handThree);
	deck.dealHand(handFour);

	cout << handOne.toString() << endl;
	cout << handTwo.toString() << endl;
	cout << handThree.toString() << endl;
	cout << handFour.toString() << endl;
	return 0;
}