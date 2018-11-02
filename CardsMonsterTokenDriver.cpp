#include <iostream>
#include "Monsters.h"
#include "Buildings.h"
#include "Cards.h"
#include "Tokens.h"
#include "BU.h"
#include "Active_Monsters.h"
#include "Units.h"
#include "Cards_Deck.h"
#include "Tokens_Deck.h"
#include <string>

using namespace std;

int main() {
	cout << "Start building deck of regular cards";
	Cards_Deck* decks = new Cards_Deck();

	Cards* regular_deck[64];
	Cards* special_deck[2];

	for (int i = 0; i < 64;  i++) {
		regular_deck[i] = decks->getRegularCard(i);
		std ::string description( regular_deck[i]->toString());
		std ::cout << description << "\n";
	}
	/*for (int i = 0; i < 2; i++) {
		special_deck[i] = decks->getSpecialCards(i);
	}*/
	
	





}