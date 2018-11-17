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

	//checking if the player has the amount of energy required to change the cards
	if (player->getMonster()->getEnergy() >=2) {
		//spending the energy to change the cards
		int energy = player->getMonster()->getEnergy();
		energy -= 2;
		player->getMonster()->setEnergy(energy);
		//changing the cards
		bool keepGoing = true;
		int i = 0;
		int counter = 0;
		int restart = 0;
		while (keepGoing = true) {
			//in the case that the array has been gone over we restart the array to 0 so that we can pass trhough it again
			if (i = 64) {
				i = 0;
				restart++;
			}//all cards have been changed we exit the loop
			else if (counter = 3) {
				keepGoing = false;
			
			}
			//case the card is already in the hands of a player
			else if (getRegularCard(i)->getStatus()==true) {
				i++;
			}
			//case went through the entire array of cards and no more cards are available i.e. restart is at 2 
			else if(restart == 2){
				cout << "The cards that you can buy are: \n" << possible_cards[0] ->toString()<< "\n" << possible_cards[1]->toString() << "\n" << possible_cards[2]->toString() << endl;
				cout << "All other cards are in the possession of other players or have been used." << endl;
				keepGoing = false;

			}
			//case where all is right, changing the cards with no problem
			else {
				possible_cards[counter] = getRegularCard(i);
				counter++;
				i++;

			
			}

		}
		//output of the new cards
		cout<< "The new cards are \n" <<possible_cards[0]->toString()<<"\n"<<possible_cards[1]->toString() << "\n" << possible_cards[2]->toString() << endl;

	}
	//message in the case the player does not have enough energy to change the cards
	else
		cout << "You do not have enough energy to change the cards. Please choose one of the current cards or move on." << endl;

}

void BuyCards::showPossibleBuy() {

}

void BuyCards::buyCards(string cardName, player* player) {



}