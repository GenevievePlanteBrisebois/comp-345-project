/*
created by Genevieve Plante-Brisebois
40003112
comp 345 fall 2018
*/

#include<iostream>

#include "Move.h"

int main() {
	Move* move_object = new Move();

	player* p1 = new player();
	player* p2 = new player();

	Map* m = new Map();
	 
	move_object->move(p1,m);
	move_object->move(p2, m);

}