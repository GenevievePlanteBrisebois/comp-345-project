//writen by Genevieve Plante-Brisebois 4003112 comop 345 fall 2018
#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Monsters {
public:
	 Monsters();
	 Monsters(string a);
	string getName();
	int getVictoryPoint();
	int getHealth();
	bool is_monster_real(string a);
	void setHealth(int health);
	void setVictoryPoints(int victory_point);
};
