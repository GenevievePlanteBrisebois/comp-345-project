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
	bool verifyVictory(Monsters a);
	bool verifyDeath(Monsters a);
	void damageHealth(int i, Monsters monster, Monsters* pointer);
	void heal(int i, Monsters monster);
	void addVictoryPoint(int i, Monsters monster);
	void loseVictoryPoint(int i, Monsters monster);
	void death(Monsters* a);
	void eraseMonster(Monsters* a);
	void destroyAllMonsters(Monsters* a[]);
	void addEnergyPoint(int e, Monsters* a);
	void removeEnergyPoint(int e, Monsters* a);
	~Active_Monsters();
	Active_Monsters();
};