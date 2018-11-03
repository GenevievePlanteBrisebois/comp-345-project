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
	Active_Monsters::Active_Monsters() {
	
	}


