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
	string getNameFromList(int i);
	int getVictoryPoint();
	int getHealth();
	int getEnergy();
	bool is_monster_real(string a);
	void setHealth(int health);
	void setVictoryPoints(int victory_point);
	void setEnergy(int e);

};
