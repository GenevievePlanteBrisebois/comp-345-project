#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Monsters {
public:
	Monsters monsters();
	string getName();
	int getVictoryPoint();
	int getHealth();
	void setHealth(int health);
	void setVictoryPoints(int victory_point);
};

class Active_Monsters {
public:
	Monsters monsters(string a);
	bool is_monster_active(string a);
	void addActive(string name);
	bool verifyVictory(Monsters a);
	bool verifyDeath(Monsters a);
	bool is_monster_real(string a);
	void damageHealth(int i, Monsters monster);
	void heal(int i, Monsters monster);
	void addVictoryPoint(int i, Monsters monster);
	void loseVictoryPoint(int i, Monsters monster);
	void death(Monsters a);
	void eraseMonster(Monsters a);
	void destroyAllMonsters(Monsters a[]);
	~Active_Monsters();
};