//
// Created by nasir on 3/23/16.
//

#include "Deck.h"

Deck::Deck(){
	initDecks();
}


const string Deck::HEART_SYMBOL("♥");
const string Deck::DIAMOND_SYMBOL("♦");
const string Deck::SPADE_SYMBOL("♠");
const string Deck::CLUB_SYMBOL("♣");

const vector<string> Deck::BASE_CARD_ARRAY = {"2", "3", "4", "5", "6",
                                              "7", "8", "9", "10",
                                              "J", "Q", "K", "A"};

const vector<string> Deck::SYMBOL_ARRAY = {HEART_SYMBOL, DIAMOND_SYMBOL,
                                           SPADE_SYMBOL, CLUB_SYMBOL};

void Deck::initDecks() {
	vector<Card> *currVector = nullptr;

	string suit;

	for(int i =0; i<SYMBOL_ARRAY.size(); i++){
		switch (i){
			case 0:
				currVector = &hearts;
				suit = HEART_SYMBOL;
				break;
			case 1:
				currVector = &diamonds;
				suit = DIAMOND_SYMBOL;
				break;
			case 2:
				currVector = &spades;
				suit = SPADE_SYMBOL;
				break;
			case 3:
				currVector = &clubs;
				suit = CLUB_SYMBOL;
				break;
			default:
				cout << "Fail" << endl;
				return;
		}

		for (int j = 0; j<BASE_CARD_ARRAY.size(); j++){
			currVector->push_back(Card(suit, BASE_CARD_ARRAY.at(j)));
		}
	}
}

void Deck::dealHand(Hand &h) {
	for (int i = 0; i < 13; i++) {
		int randomDeck = rand() % 4;
		vector<Card> *currVector = nullptr;

		switch (randomDeck) {
			case 0:
				currVector = &hearts;
				break;
			case 1:
				currVector = &diamonds;
				break;
			case 2:
				currVector = &spades;
				break;
			case 3:
				currVector = &clubs;
				break;
			default:
				cout << "fail2" << endl;
				return;
		}

		int randomIndex = 0;
		//TODO:make it include all indexes
		//Currently it is not including three elements
		if (currVector->size() > 0) {
			randomIndex = rand() % currVector->size();
			h.addCard(currVector->at(randomIndex));
			remove_at(*currVector, randomIndex);
		}else{
			while(!currVector->size()>0){
				if(currVector==&hearts){currVector = &diamonds;}
				else if(currVector==&diamonds){currVector = &spades;}
				else if(currVector==&spades){currVector=&clubs;}
				else if(currVector == &clubs){currVector=&hearts;}
			}

			h.addCard(currVector->at(0));
			remove_at(*currVector, 0);
		}
	}
}

template<typename T>
void Deck::remove_at(std::vector<T> &v, typename std::vector<T>::size_type n) {
	std::swap(v[n], v.back());
	v.pop_back();
}

void Deck::printDecks() {
	cout << hearts.size() << endl;
	cout << diamonds.size() << endl;
	cout << spades.size() << endl;
	cout << clubs.size() << endl;


	string s;

	vector<Card> *currHand = nullptr;
	currHand = &hearts;
	for(int i = 0; i<currHand->size(); i++){
		cout <<" "+currHand->at(i).getSuit() + currHand->at(i).getValue();
	}
	cout<< endl;

	currHand = &diamonds;
	for(int i = 0; i<currHand->size(); i++){
		cout << " "+currHand->at(i).getSuit() + currHand->at(i).getValue();
	}
	cout<< endl;

	currHand = &spades;
	for(int i = 0; i<currHand->size(); i++){
		cout<< " "+currHand->at(i).getSuit() + currHand->at(i).getValue();
	}
	cout<< endl;

	currHand = &clubs;
	for(int i = 0; i<currHand->size(); i++){
		cout << " "+currHand->at(i).getSuit() + currHand->at(i).getValue();
	}
	cout << endl;

	cout << endl;

}

