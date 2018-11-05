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
	int energy_point;
	int countAttack;


	//making getters and setters for the elements of the monsters

	string Monsters::getName() {
		return monster_name;
	}
	string Monsters::getNameFromList(int i) {
		return name_monsters[i];
	}
	int Monsters::getVictoryPoint() {
		return monster_victory_point;

	}
	int Monster::getCountAttack() {
		return countAttack;
	}
	int  Monsters::getHealth() {
		return monster_health;
	}
	int Monsters::getEnergy() {
		return energy_point;
	}
	void Monsters::setCountAttack(int i) {
		countAttack = 0;
	}
	void  Monsters::setHealth(int health) {
		monster_health = health;
	}

	void  Monsters::setVictoryPoints(int victory_point) {
		monster_victory_point = victory_point;
	}
	void Monsters::setEnergy(int e) {
		energy_point = e;
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
			energy_point = 0;
			countAttack = 0;
		}
		else
			throw invalid_argument("Name is not a valid Monster Name. Pick from the available names");

	}




	void Monsters::addEnergyPoint(int e, Monsters* pointer) {
		int tempEnergy = pointer->getEnergy();
		tempEnergy += e;
		pointer->setEnergy(tempEnergy);
	}
	void Monsters::removeEnergyPoint(int e, Monsters* pointer) {
		int tempEnergy = pointer->getEnergy();
		tempEnergy -= e;
		if (tempEnergy < 0) {
			cout << "Not enough Energy to spend. Cannot remove more than the available amount of energy:" << pointer->getEnergy();
		}
		else {
			pointer->setEnergy(tempEnergy);
			cout << "You have " << pointer->getEnergy() << " energy points left";

		}
	}
	//making functions that verify the various components (death, victory, if monster is available)

			//verifying if the monster has the required number of victory points to win the game
	bool Monsters::verifyVictory(Monsters* a) {
		bool victory;

		if (a.getVictoryPoint() >= 20)
			return victory = true;
		else
			return victory = false;

	}
	//verifying if the monster has depleated all of its health and needs to be destroyed

	bool Monsters::verifyDeath(Monsters* a) {
		bool dead;
		if (a.getHealth() <= 0)
			return dead = true;
		else
			return dead = false;

	}



	//making a function to take away health
	void Monsters::damageHealth(int i,  Monsters* pointer) {
		int  health = pointer.getHealth();

		health = health - i;

		pointer.setHealth(health);

		if (verifyDeath(pointer) == true)
			death(pointer);
		if (this->getName() != pointer->getName()) {
			countAttack += 1;
		}

	}
	//making function to heal
	void Monsters::heal(int i, Monsters* monster) {
		int health = monster.getHealth();

		health = health + i;

		if (health > 10)
			health = 10;

		monster.setHealth(health);
		

	}
	//making function to add victory points
	void Monsters::addVictoryPoint(int i, Monsters* monster) {
		int vp = monster.getVictoryPoint();

		vp = vp + i;

		monster.setVictoryPoints(vp);

		verifyVictory(monster);
	}
	//making function to take away victory points
	void Monsters::loseVictoryPoint(int i, Monsters* monster) {
		int vp = monster.getVictoryPoint();

		vp = vp - i;

		if (vp <= 0)
			vp = 0;

		monster.setVictoryPoints(vp);
	}
	//destructor(monster died)
	void Monsters::death(Monsters* a) {

		delete a;

	}


