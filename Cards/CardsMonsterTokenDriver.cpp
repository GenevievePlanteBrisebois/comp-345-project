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
	
	string description1;
	string description2;

	for (int i = 0; i < 64;  i++) {
		
		Cards* pointer = decks->getRegularCard(i);
		description1=( pointer->toString());
		cout << description1 << "\n\n";
	}
	
	cout << "Building deck of special cards\n";
	for (int i = 0; i < 2; i++) {
		
		description2=(decks->getSpecialCards(i)->toString());
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

	BU* bu = new BU();
	Buildings* start_set[45];

	bu->build_building_deck();


	cout << "list of possible monsters a player can take\n";

	Active_Monsters * monsters = new Active_Monsters();
	cout<<monsters->getNameFromList(0)<<"\n";
	cout << monsters->getNameFromList(1) << "\n";
	cout << monsters->getNameFromList(2) << "\n";
	cout << monsters->getNameFromList(3) << "\n";
	cout << monsters->getNameFromList(4) << "\n";
	cout << monsters->getNameFromList(5) << "\n";




	return 0;








	
	





}