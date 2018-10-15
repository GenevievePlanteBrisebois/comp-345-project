//class written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018
#include <iostream>
#include <stdexcept>
#include "Monsters.h"
using namespace std;
// making a class for the monsters. there are 6 monsters and they all start with the same stats
//class monster is the parent and ActiveMonster is the child class. When calling to the monsters the other classes should call to the ActiveMonster Class.  


	string name_monsters[6] = { "Mantis", "Captain Fish", "Dragonis", "Kong", "Sheriff", "Rob" };
	string monster_name;
	int monster_health;
	int monster_victory_point;



	//making getters and setters for the elements of the monsters
	string Monsters::getName() {
		return monster_name;
	}

	int Monsters::getVictoryPoint() {
		return monster_victory_point;

	}

	int  Monsters::getHealth() {
		return monster_health;
	}

	void  Monsters::setHealth(int health) {
		monster_health = health;
	}

	void  Monsters::setVictoryPoints(int victory_point) {
		monster_victory_point = victory_point;
	}
	//function to verify that the name is part of the name array and as such a valid monster name

	bool  Monsters:: is_monster_real(string a) {

		bool real;

		for (int i = 0; i < sizeof(name_monsters); i++) {
			if (name_monsters[i] == a) {
				real = true;
				break;
			}
			else {
				real = false;

			}

		}return real;

	}

	  Monsters::Monsters() {
	}

	//a monster constructor in order to get the 
	Monsters::Monsters(string a) {
		if (is_monster_real(a) == true) {

			monster_name = a;
			monster_health = 10;
			monster_victory_point = 0;
		}
		else
			throw invalid_argument("Name is not a valid Monster Name. Pick from the available names");

	}






