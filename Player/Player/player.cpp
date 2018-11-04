//since the headers of the other parts are in other folders we need to put the path that leads to the header. The path will need to be adapted according to the machine it runs on
//file created by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

//not including all of the cards classes in order to not import methods that are not relevant to the player class
#include <iostream>
#include <cstdlib>
#include "player.h"
//includes of .h that are in different solutions
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Tokens.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Dice\Dice.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Map Implementation\Map.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Map Implementation\Borough.h"

//starting to write the player methods
Monsters* player_monster;
Tokens* player_tokens[20];
Cards* player_cards[10];

//variables to be able to keep track of the dices and what to do with the results 
Dice* dices = new Dice[6];
int energy;
int attack;
int destruction;
int heal;
int celebrity;
int ouch;
//variable to store the position of the player. refers to the index in the map borough array
int position;
//constructors and destructors
player::player() {
	player_monster = new Monsters();
	Tokens* player_tokens[20];
	Cards* player_cards[10];

}

player::~player(){
	delete player_monster;
	delete [] * player_tokens;
	delete[] * player_cards;
	delete[] * dices;
}

//setters and getters
void player::setMonster(Monsters* a) {
	player_monster = a;

}

void player::setTokens(Tokens* t, int i) {
	player_tokens[i] = t;
}

void player::setTokens(Tokens* a) {
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] == nullptr) {
			player_tokens[i] = a;
			break;
		}
	}
}
void player::setCard(Cards* a) {
	for (int i = 0; i < 20; i++) {
		if (player_cards[i] == nullptr) {
			player_cards[i] = a;
			break;
		}
	}
}

void player::setPosition(int i) {
	position = i;
}

int player::getPosition() {
	return position;
}
Cards* player::getCard(Cards* a) {
	string name = a->getName();
	for (int i = 0; i < 20; i++) {
		if (player_cards[i]->getName() == name) {
			return player_cards[i];
			break;
		}
	}

}



Monsters* player::getMonster() {
	return player_monster;
}

Tokens* player::getToken(int i) {
	return player_tokens[i];
}


//to make the monster for the player will be in the driver or in the driver of the game.
//all necessary methods to create/add a monster are in the monster and active_monsters classes

//dice rolling methods
//create six dice and roll them up to three times. 

void player::rollDice() {
	

	cout << "First Roll of the dices" << endl;

	for (int i = 0; i < 6; i++) {
		int face = rand() % 6;
		cout << "Dice "<< i <<":  "<< endl;
		dices[i].rollDice(face);
	}

	/*
	for loops in order to reroll up to two times. 	
	*/
	for (int i = 0; i < 2; i++) {
		cout << "Do you wish to reroll? y/n" << endl;
		string ans;
		cin >> ans;


		if (ans == "y") {
			cout << "We will now check which dices you wish to reroll.";

			//nested for loop for simplicity. The number of iteration is very low so it was deemed acceptable even if the complexity suffers
			for (int j = 0; j < 6; j++) {
				cout << "Do you wish to reroll dice "<< j <<" y/n ?";
				string answer;
				cin >> answer;
				if (answer == "y") {
					int face2 = rand() % 6;
					dices[j]. rollDice(face2);
				
				}	
			}

			//if it was the final roll
			if (i == 1) {
				cout << "After final rolling of the dices these are your dices:" << endl;

				for (int j = 0; j < 6; j++) {
					cout << dices[j].getDiceFace() << endl;
				}
			
			}
			//if it was the second roll
			else if (i == 0) {
			
				cout << "After rolling for a second time these are your dices:" << endl;

				for (int j = 0; j < 6; j++) {
					cout << dices[j].getDiceFace() << endl;
				}

				cout << "You can still reroll your dices one time. " << endl;
			}


		}
		//breaking the for loop in the case that the player decides against rerolling
		else
			break;
		



	}
}
//it will take in the result of the dice and then it will convert the result in what the player can use
/*
faceList[0] = "Energy";
	faceList[1] = "Attack";
	faceList[2] = "Destruction";
	faceList[3] = "Heal";
	faceList[4] = "Celebrity";
	faceList[5] = "Ouch!"

*/
void player::resolveDice() {
	//resetting the tracking variables to 0 in order to track the proper variables of the new dice roll
	energy = 0;
	attack = 0;
	destruction = 0;
	heal = 0;
	celebrity = 0;
	ouch =0;
	//calculating how many of each is present in the dice rolls in order to know what can be done 
	for (int i = 0; i < 6; i++) {
		if (dices[i].getDiceFace() == "Energy") {
			energy += 1;
		}else if (dices[i].getDiceFace() == "Attack") {
			attack += 1;
		}
		else if (dices[i].getDiceFace() == "Destruction") {
			destruction += 1;
		}
		else if (dices[i].getDiceFace() == "Heal") {
			heal += 1;
		}
		else if (dices[i].getDiceFace() == "Celebrity") {
			celebrity += 1;
		}
		else if (dices[i].getDiceFace() == "Ouch!") {
			ouch += 1;
		}
	}

	cout << "You have a total of :" << endl;
	cout << energy << " Engergy" << endl;
	cout << attack << " Attack" << endl;
	cout << destruction << " Destruction" << endl;
	cout << heal << " Heal" << endl;
	cout << celebrity << " Celebrity" << endl;
	cout << ouch << " Ouch!" << endl;


	player_monster->addEnergyPoint(energy, player_monster);
	player_monster->heal(heal, player_monster);
	


}

//map methods

//tokens methods
//methods to add and remove tokens from the player

void player::addToken(Tokens* token) {
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] == nullptr) {
			player_tokens[i] = token;
		}
	}
}

void player::removeToken(Tokens* token) {
	string type = token->getType();
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] != nullptr && player_tokens[i]->getType() == token->getType()) {
			player_tokens[i] = nullptr;
			break;//end the loop so that we do not go through the whole loop
		}	
	}

}


//cards methods to buy and use cards

void player::useCard(Cards* a) {
	string name = a->getName();
	for (int i = 0; i < 20; i++) {
		if (player_cards[i]->getName() == name) {
			 player_cards[i]== nullptr;
			break;
		}
	}


}

void player::buyCard( Cards* a) {
	int current_energy = player_monster->getEnergy();
	int cost = a->getCost();
	if (current_energy - cost < 0) {
		cout << "you do not have enough energy to buy this card. You have " << current_energy << " energy at the moment.";
	}
	else {
		int energy_left = current_energy - cost;
		cout << "You have bought card " << a->getName() << "for the cost of " << cost << " energy. You have " << energy_left << " energy left" << endl;
		this->setCard(a);
	}
}

void player::move(string borough, Map m) {
	bool statusLM = m.getBorough(8)->getStatus();
	bool statusMM = m.getBorough(9)->getStatus();
	bool statusUM = m.getBorough(10)->getStatus();
	//cases to move to or within manhattan
	if (borough == "Lower Manhattan" && statusLM == false && statusMM == false && statusUM == false) {
		//setting previous position to empty
		if (position != NULL) {
			m.setBorough(position, false);
		}
		//moving to new borough
		position = 8;
		m.setBorough(8, true);
	}
	else if (borough == "Mid Manhattan" && position == 8) {
		m.setBorough(8, false);
		m.setBorough(9, true);
		position = 9;
	}
	else if (borough == "Upper Manhattan" && position == 9) {
		m.setBorough(9, false);
		m.setBorough(10, true);
		position = 10;

	}


	//other boroughs
	for (int i = 0; i < 8; i++) {
		string name = m.getBorough(i)->getName();
		bool status = m.getBorough(i)->getStatus();
		
		 if (borough == name && status == false) {
			 if (position != NULL) {
				 m.setBorough(position, false);
			 }
			 position = i;
			m.setBorough(i, true);
			break;
		
		}
		else
			cout << "This borough is full. Choose another borough or stay in your current borough" << endl;

	
	}
}

