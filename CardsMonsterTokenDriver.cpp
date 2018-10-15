#include <iostream>
#include "Monsters.h"
#include "Buildings.h"
#include "Cards.h"
#include "Tokens.h"
#include "BU.h"
#include "Active_Monsters.h"
#include "Units.h"
#include "Cards_Deck.h"
#include <string>

using namespace std;

int main() {
	cout << "Start building deck of regular cards \n";
	Cards_Deck* decks = new Cards_Deck();
	decks->build_regular_deck();
	decks->build_special_deck();

	Cards* regular_deck[64];
	string description1;
	string description2;

	for (int i = 0; i < 64;  i++) {
		regular_deck[i] = decks->getRegularCard(i);
		description1=( regular_deck[i]->toString());
		cout << description1 << "\n\n";
	}
	Cards* special_deck[2];
	cout << "Building deck of special cards\n";
	for (int i = 0; i < 2; i++) {
		special_deck[i] = decks->getSpecialCards(i);
		description2=(special_deck[i]->toString());
		cout << description2 << "\n\n";
	}

	cout << "shuffling the cards of the regular deck";




	cout << "building the Tokens";
	Tokens* token = new Tokens();
	Tokens* carapace[15];
	for (int i = 0; i < 15; i++) {
		carapace[i] = token->create_carapace();
		cout << carapace[i]->getType()<<"\n";
	}
	Tokens* souvenir[5];
	for (int i = 0; i < 5; i++) {
		souvenir[i] = token->create_souvenir();
		cout << souvenir[i]->getType()<<"\n";
	}

	Tokens* web[13];
	for (int i = 0; i < 13; i++) {
		web[i] = token->create_web();
		cout << web[i]->getType()<<"\n";
	}

	Tokens* jinx[13];
	for (int i = 0; i < 13; i++) {
		jinx[i] = token->create_jinx();
		cout << jinx[i]->getType()<<"\n";
	}
	cout << "GETTING THE BUILDINGS FOR STARTING THE GAME \n";





	
	





}