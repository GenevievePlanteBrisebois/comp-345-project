//class written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018
#include <iostream>;
#include <stdexcept>;
using namespace std;
// making a class for the monsters. there are 6 monsters and they all start with the same stats
//class monster is the parent and ActiveMonster is the child class. When calling to the monsters the other classes should call to the ActiveMonster Class.  
class Monsters {
public:
	string name_monsters[6] = { "Mantis", "Captain Fish", "Dragonis", "Kong", "Sheriff", "Rob" };
	string name;
	int health;
	int victory_point;
	


	//making getters and setters for the elements of the monsters
	string getName() {
		return name;
	}
	
	int getVictoryPoint() {
		return victory_point;
	
	}

	int getHealth() {
		return health;
	}

	void setHealth(int health) {
		  this->health= health;
	}

	void setVictoryPoints(int victory_point) {
		this->victory_point = victory_point;
	}
	//function to verify that the name is part of the name array and as such a valid monster name

	bool is_monster_real(string a) {

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

	Monsters monsters() {
		string name = "";
		int health = 10;
		int victory_points = 0;
	}

	//a monster constructor in order to get the 
	Monsters monsters(string a) {
		if (is_monster_real(a) == true) {
			
				name = a;
				health = 10;
				victory_point = 0;			
		}
		else
			throw invalid_argument("Name is not a valid Monster Name. Pick from the available names");

	}
};
//making a constructor
//Monsters :: Monsters() {
	
//}







class Active_Monsters : public Monsters {
public:
	string name;
	int health;
	int victory_point;
	Monsters active_monsters[6];
	Monsters* active_monsters_head_pointer = &active_monsters[0];


	

	

		//verifying if the monster is already chosen/if a certain monster is already active in the game
		bool is_monster_active(string a){
			bool active;
			for (int i = 0; i < sizeof(active_monsters); i++) {
				if (a == active_monsters[i].getName())
					active = true;
				else
					active = false;
			}
		}

		//make sure to verify that the monster is not already active first so that it is valid to take that monster
		//making a method in order to add a monster to the array of active monsters
		void addActive(string name) {
			bool keepGoing = true;

			while (keepGoing == true) {
				int i = 0;

				if (active_monsters[i].getName() != "")
					i++;
				else {
					Monsters newbie = monsters();
					Monsters* newb = &newbie;
					newbie = monsters(name);
					active_monsters[i] = newbie;
				}
			}
			}
		
//making functions that verify the various components (death, victory, if monster is available)

	//verifying if the monster has the required number of victory points to win the game
bool verifyVictory(Monsters a) {
	bool victory;

	if (a.getVictoryPoint >= 20)
		return victory = true;
	else
		return victory = false;

}
//verifying if the monster has depleated all of its health and needs to be destroyed

bool verifyDeath(Monsters a) {
	bool dead;
	if (a.getHealth <= 0)
		return dead = true;
	else
		return dead = false;

}



//making a function to take away health
void damageHealth(int i, Monsters monster, Monsters* pointer) {
	int  health = monster.getHealth();

	health = health - i;

	monster.setHealth(health);

	if (verifyDeath(monster) == true)
		death(pointer);

}
//making function to heal
void heal(int i, Monsters monster) {
	int health = monster.getHealth;

	health = health + i;

	if (health > 10)
		health = 10;

	monster.setHealth(health);

}
//making function to add victory points
void addVictoryPoint(int i, Monsters monster) {
	int vp = monster.getVictoryPoint();

	vp = vp + i;

	monster.setVictoryPoints(vp);

	verifyVictory(monster);
}
//making function to take away victory points
void loseVictoryPoint(int i, Monsters monster) {
	int vp = monster.getVictoryPoint();

	vp = vp - i;

	if (vp <= 0)
		vp = 0;

	monster.setVictoryPoints(vp);
}
//destructor(monster died)
void death(Monsters* a) {
	
	delete a;

}
//destructor(to erase a monster)
void eraseMonster(Monsters*  a) {

	delete a;
}
//destructor(to erase all monsters)
void destroyAllMonsters(Monsters a[]) {
	
	delete[] a;

}

// making the destructor

~Active_Monsters() {

	delete [] active_monsters;

}


};

