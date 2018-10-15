//class written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018
#include <iostream>
#include <stdexcept>
#include "Monsters.h"
#include "Active_Monsters.h"
using namespace std;


	string name;
	int health;
	int victory_point;
	Monsters* active_monsters[6];

	//verifying if the monster is already chosen/if a certain monster is already active in the game
	bool Active_Monsters::is_monster_active(string a) {
		bool active;
		for (int i = 0; i < sizeof(active_monsters); i++) {
			if (a == active_monsters[i]->getName())
				active = true;
			else
				active = false;
		}
		return active;
	}

	//make sure to verify that the monster is not already active first so that it is valid to take that monster
	//making a method in order to add a monster to the array of active monsters
	void Active_Monsters::addActive(string name) {
		bool keepGoing = true;

		while (keepGoing == true) {
			int i = 0;

			if (active_monsters[i]->getName() != "")
				i++;
			else {
				Monsters* newbie = new Monsters(name);
				active_monsters[i] = newbie;
			}
		}
	}

	//making functions that verify the various components (death, victory, if monster is available)

		//verifying if the monster has the required number of victory points to win the game
	bool Active_Monsters::verifyVictory(Monsters a) {
		bool victory;

		if (a.getVictoryPoint() >= 20)
			return victory = true;
		else
			return victory = false;

	}
	//verifying if the monster has depleated all of its health and needs to be destroyed

	bool Active_Monsters::verifyDeath(Monsters a) {
		bool dead;
		if (a.getHealth() <= 0)
			return dead = true;
		else
			return dead = false;

	}



	//making a function to take away health
	void Active_Monsters::damageHealth(int i, Monsters monster, Monsters* pointer) {
		int  health = monster.getHealth();

		health = health - i;

		monster.setHealth(health);

		if (verifyDeath(monster) == true)
			death(pointer);

	}
	//making function to heal
	void Active_Monsters::heal(int i, Monsters monster) {
		int health = monster.getHealth();

		health = health + i;

		if (health > 10)
			health = 10;

		monster.setHealth(health);

	}
	//making function to add victory points
	void Active_Monsters::addVictoryPoint(int i, Monsters monster) {
		int vp = monster.getVictoryPoint();

		vp = vp + i;

		monster.setVictoryPoints(vp);

		verifyVictory(monster);
	}
	//making function to take away victory points
	void Active_Monsters::loseVictoryPoint(int i, Monsters monster) {
		int vp = monster.getVictoryPoint();

		vp = vp - i;

		if (vp <= 0)
			vp = 0;

		monster.setVictoryPoints(vp);
	}
	//destructor(monster died)
	void Active_Monsters::death(Monsters* a) {

		delete a;

	}
	//destructor(to erase a monster)
	void Active_Monsters::eraseMonster(Monsters*  a) {

		delete a;
	}
	//destructor(to erase all monsters)
	void Active_Monsters::destroyAllMonsters(Monsters * a[]) {

		delete[] a;

	}

	// making the destructor

	Active_Monsters::~Active_Monsters() {

		delete[] active_monsters;

	}




