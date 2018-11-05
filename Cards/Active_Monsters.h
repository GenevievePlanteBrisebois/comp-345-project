//writen by Genevieve Plante-Brisebois 4003112 comop 345 fall 2018
#pragma once
#include <iostream>
#include <stdexcept>
#include "Monsters.h"
using namespace std;


class Active_Monsters: public Monsters {
public:
	bool is_monster_active(string a);
	void addActive(string name);
	Monsters* getActive(int i);
	
	void eraseMonster(Monsters* a);
	void destroyAllMonsters(Monsters* a[]);
	~Active_Monsters();
	Active_Monsters();
};