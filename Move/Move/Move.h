/*
created by Genevieve Plante-Brisebois
40003112
comp 345 fall 2018
*/

#pragma once
#include<iostream>
#include "../Player/Player/player.h"
#include "MainLoop/MainLoop/MainLoop.h"

class Move {
public:
	Move();
	~Move();

	void move(player* player, Map* m);


};