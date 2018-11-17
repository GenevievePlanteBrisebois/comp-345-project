/*
written by Genevieve Plante-Brisebois
40003112
COMP 345 Fall 2018


This class implements the rules of card buying. In the player class there is a basic buying cards method 
but it only implements the restriction of "does the player have enough energy to buy the card or not". This
class will implement the manipulation of the possible cards to buy, spending energy in order to change the possible 
cards to buy and then finally the buying of the cards as in the player class. 
*/




#include <iostream>
#include "BuyCards.h"
#include"Player/Player/player.h"
//class variable, an array of 3 card names
Cards* possible_cards[3];

//Constructors and deconstructors
BuyCards::BuyCards() {
	//filling up the array of possible cards to buy by the first 3 regular cards in the cards deck. the game will be new when calling the constructor so no cards will be in the hands of any player.
	possible_cards[0] = getRegularCard(0);
	possible_cards[1] = getRegularCard(1);
	possible_cards[2] = getRegularCard(2);
}

BuyCards::~BuyCards() {
	delete [] possible_cards;
}

void BuyCards::changePossibleBuy(player* player) {
	bool keepGoing = true;
	int i = 0;
	while (keepGoing = true) {
		//in the case that the array has been gone over we restart the array to 0 so that we can pass trhough it again
		if (i = 64)
			i = 0;
		

	}

}

void BuyCards::showPossibleBuy() {

}

void BuyCards::buyCards(string cardName, player* player) {



}