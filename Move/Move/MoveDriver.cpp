/*
created by Genevieve Plante-Brisebois
40003112
comp 345 fall 2018
*/

#include<iostream>

#include "Move.h"
#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"

#include "../comp345-kingsOfNY/Player/Player/player.h"

int main() {
	Move* move_object = new Move();

	player* p1 = new player();
	player* p2 = new player();

	Monsters* pl1 = new Monsters("Mantis");
	Monsters* pl2 = new Monsters("Captain Fish");

	p1->setMonster(pl1);
	p2->setMonster(pl2);

	Map* m = new Map();
	 
	move_object->move(p1,m);
	move_object->move(p2, m);

	p1 = NULL;
	p2 = NULL;
	m = NULL;

	delete p1;
	delete p2;
	delete m;

	return 0;
}