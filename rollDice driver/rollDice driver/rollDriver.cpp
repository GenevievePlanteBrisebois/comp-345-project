/*
created by genevieve Plante-Brisebois
40003112
fall 2018 comp345

driver to implement the dice roll of the player and dice resolution as they already do what is asked in a2
*/

#include "../comp345-kingsOfNY/Player/Player/player.h"

#include <iostream>
using namespace std;
int main() {
	player* p1 = new player();
	player* p2 = new player();
	player* players[2];

	Monsters* m1 = new Monsters("Captain Fish");
	Monsters* m2 = new Monsters("Mantis");

	p1->setMonster(m1);
	p2->setMonster(m2);

	Map* m = new Map();
	Active_Monsters* b = new Active_Monsters();
	b->addActive(m1->getName());
	b->addActive(m2->getName());

	Monsters* active_m[2];
	active_m[0] = b->getActive(0);
	active_m[1] = b->getActive(1);

	Cards_Deck* cards = new Cards_Deck();
	BU* bu = new BU();


	p1->rollDice();
	p1->resolveDice(m, active_m, bu, cards, players);



	return 0;
}