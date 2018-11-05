/*
created by Genevieve Plante-Brisebois
40003112
comp 345 fall 2018
*/

#pragma once
#include<iostream>
#include "../comp345-kingsOfNY/Player/Player/player.h"
#include "MainLoop/MainLoop/MainLoop.h"
#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"

class Move {
public:
	Move();
	~Move();

	void move(player* player, Map* m);


};