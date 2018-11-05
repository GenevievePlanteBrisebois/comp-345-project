/*
created by genevieve Plante-Brisebois
40003112
fall 2018 comp345

driver to implement the dice roll of the player and dice resolution as they already do what is asked in a2
*/

#include "../comp345-kingsOfNY/Player/Player/player.h"
#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Cards/Cards.h"
#include "../comp345-kingsOfNY/Cards/Buildings.h"
#include "../comp345-kingsOfNY/Cards/Units.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Cards/Monsters.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"

#include <iostream>

int main() {
	player* p1 = new player();
	Monsters* m1 = new Monsters("Captain Fish");

	p1->setMonster(m1);



	p1->rollDice();




	return 0;
}