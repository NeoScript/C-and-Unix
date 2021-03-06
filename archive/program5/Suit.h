//
// Created by nasir on 3/28/16.
//
/**
* this class is just used for inheritence
* the faces all are children of the Suit class, and extend the virtual function in order to hold their Suit value
*/

#ifndef PROGRAM5_SUIT_H
#define PROGRAM5_SUIT_H

#include <string>

	class Suit{
public:
	virtual std::string getString() = 0;
};

class Spade : public Suit{
	std::string getString() {
		return "♠";
	}
};

class Heart : public Suit{
	std::string getString() {
		return "♥";
	}
};

class Diamond : public Suit{
	std::string getString() {
		return "♦";
	}
};

class Club : public Suit{
	std::string getString() {
		return "♣";
	}
};

#endif //PROGRAM5_SUIT_H
