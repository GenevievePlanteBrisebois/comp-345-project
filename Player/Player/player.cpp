//since the headers of the other parts are in other folders we need to put the path that leads to the header. The path will need to be adapted according to the machine it runs on
//file created by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

//not including all of the cards classes in order to not import methods that are not relevant to the player class
#include <iostream>
#include <cstdlib>
#include "player.h"
//includes of .h that are in different solutions
#include "../comp345-kingsOfNY/Observer.h"
#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"
#include "../comp345-kingsOfNY/Observer.h"
#include "..\comp345-kingsOfNY\PlayerObserver.h"

using namespace std;

//starting to write the player methods
Monsters* player_monster;
Tokens* player_tokens[20];
Cards* player_cards[10];
Dice * dices = new Dice[6];
int destruction_points;
//variables to be able to keep track of the dices and what to do with the results 

int energy;
int attack;
int destruction;
int heal;
int celebrity;
int ouch;
//variable to store the position of the player. refers to the index in the map borough array
int position;

//observer
PlayerObserver* player_ob;
//constructors and destructors

player::player() {
	player_monster = new Monsters();
	Tokens* player_tokens[20];
	Cards* player_cards[10];
	destruction_points = 0;
	player_ob = new PlayerObserver();
	position = NULL;

	
}

player::~player(){
	player_monster = NULL;
	player_ob = NULL;
	delete player_monster;
	delete [] * player_tokens;
	delete[] * player_cards;
	delete[]  dices;
	delete player_ob;
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

Monsters * player::getPlayer(string name, Active_Monsters * a) {
	for (int i = 0; i < 6; i++) {
		if (a->getActive(i)->getName() == name) {
			return a->getActive(i);
		}
	}
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

void player::removeDestructionPoints(int i) {
	int d = destruction_points - i;
	if (d < 0)
		cout << "you do not have enough destruction points" << endl;
	else {
		destruction_points -= i;
		cout << "You have " << destruction_points << " destruction points left" << endl;
	}
}

int player::getDestructionPoints() {
	return destruction_points;
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
	player_ob->notifyPlayerAction("Rolling Dice");

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
		player_ob->notifyPlayerAction("Reroll dice");
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
some steps will need to be taken in the driver in order to do all required actions for :
*/

void player::resolveHeal(int heal) {

	player_monster->heal(heal, player_monster);
}

void player::resolveEnergy(int energy) {
	player_monster->addEnergyPoint(energy, player_monster);
}

void player::resolveCelebrity(int celebrity, Cards_Deck*  cards, player* players[]) {


	if (celebrity >= 3) {
		int vp = celebrity - 3;
		int total = 1 + vp;
		player_monster->addVictoryPoint(total, player_monster);
		cout << "You get the Superstar Card" << endl;
		Cards* super = cards->getSpecialCards(1);
		buyCard(super);
		string player2 = super->getPlayerName();
		if (player2 == "")
			super->setPlayerName(player_monster->getName());
		else {
			super->setPlayerName(player_monster->getName());
			for (int i = 0; i < 6; i++) {
				string player2name = players[i]->getMonster()->getName();
				if (player2name == player2) {
					players[i]->useCard(super);
				}
			}
		}

	}
}


void player::resolveOuch(int ouch, Map* m, player* players[], Cards_Deck* cards, BU* bu) {
	if (ouch == 1) {
		int count = 0;
		string area = m->getBorough(position)->getBName();
		//counting the number of units in the borough of the player
		for (int i = 0; i < 7; i++) {
			if (bu->get_unit_from_set(i, area) != nullptr)
				count++;
		}
		player_monster->damageHealth(count, player_monster);

	}
	else if (ouch == 2) {
		int count = 0;
		string area = m->getBorough(position)->getBName();
		//counting the number of units in the borough of the player
		for (int i = 0; i < 7; i++) {
			if (bu->get_unit_from_set(i, area) != nullptr)
				count++;
		}

		string player2name;
		//verify if there are more monsters in the borough
		for (int i = 0; i < 11; i++) {
			Borough * maparea = m->getBorough(i);
			if (maparea->getBName() == area && maparea->getPlayerName() != player_monster->getName()) {
				player2name = maparea->getPlayerName();

			}
			else
				player2name = "";
			//clean up pointer
			delete maparea;
		}
		//get the second player


		//if there is another player in the area, damage health of both
		if (player2name != "") {
			player* player2area;
			for (int i = 0; i < 6; i++) {
				if (players[i]->getMonster()->getName() == player2name)
					player2area = players[i];
				else
					player2area = nullptr;
			}
			player2area->getMonster()->damageHealth(count, player2area->getMonster());
			player_monster->damageHealth(count, player_monster);
			//clean up pointer created for the execution of this block
			delete player2area;
		}//if there is no other player in the area damage only self
		else
			player_monster->damageHealth(count, player_monster);

	}
	else if (ouch >= 3) {
		//adding the card to the 
		player_monster->addVictoryPoint(3, player_monster);
		cout << "You get the Statue of Liberty Card" << endl;
		Cards* super = cards->getSpecialCards(0);
		buyCard(super);
		string player2 = super->getPlayerName();
		//case no one had the card previously
		if (player2 == "")
			super->setPlayerName(player_monster->getName());
		//case someone had the card previously. removing vp from previous owner
		else {
			super->setPlayerName(player_monster->getName());
			for (int i = 0; i < 6; i++) {
				string player2name = players[i]->getMonster()->getName();
				if (player2name == player2) {
					players[i]->useCard(super);
					players[i]->getMonster()->loseVictoryPoint(3, players[i]->getMonster());
				}
			}
			//doing the effect of the ouch on all monsters
			//doing a for loop to affect each monster one at the time
			for (int i = 0; i < 11; i++) {
				//if borough occupied execute else move3 on
				if (m->getBorough(i)->getBoroughStatus() == true) {

					string player1name = m->getBorough(i)->getPlayerName();
					string areaName = m->getBorough(i)->getBName();
					int count = 0;
					//counting the number of units in the borough of the player
					for (int i = 0; i < 7; i++) {
						if (bu->get_unit_from_set(i, areaName) != nullptr)
							count++;
					}
					//getting the player
					for (int i = 0; i < 6; i++) {
						if (players[i]->getMonster()->getName() == player1name) {

							//doing damage to the player
							player * player1;
							player1 = players[i];
							player1->getMonster()->damageHealth(count, player_monster);

							//clean up the pointer
							delete player1;
							break;
						}
					}




				}

			}


		}
	}
}


void player::resolveDestruction(int destruction, BU* bu, Map* m) {


	destruction_points = destruction;
	while (destruction_points > 0) {
		string b = m->getBorough(position)->getBName();
		Buildings* building;
		Units* unit;
		//checking if the player wants to destroy the building present in his borough
		for (int i = 0; i < 7; i++) {
			if (bu->get_building_from_set(i, b) != nullptr && bu->get_building_from_set(i, b)->getDurability() <= destruction_points) {
				cout << "There is a building in your borough but you do not have enough destruction points to destroy it. " << endl;
				break;
			}
			else if (bu->get_building_from_set(i, b) != nullptr) {
				building = bu->get_building_from_set(i, b);
				string build = building->getType();
				int durability = building->getDurability();
				string rewardT = building->getRewardType();
				int reward = building->getReward();
				cout << "You have in your burrough the building " << build << endl;
				cout << "Durability: " << durability << endl;
				cout << "Reward:  " << reward << " " << rewardT << endl;

				cout << "Do you wish to destroy the building? y/n" << endl;
				string answer;
				cin >> answer;

				if (answer == "y") {
					bu->destroy_building(durability, building, b);
					if (rewardT == "heal") {
						player_monster->heal(reward, player_monster);
					}
					else if (rewardT == "energy") {
						player_monster->addEnergyPoint(reward, player_monster);
					}
					else if (rewardT == "victory point")
						player_monster->addVictoryPoint(reward, player_monster);

				}
				delete building;
				break;

			}
		}

		//possible destruction of a unit
		for (int i = 0; i < 7; i++) {
			if (bu->get_unit_from_set(i, b) != nullptr && bu->get_unit_from_set(i, b)->getDurability() <= destruction_points) {
				cout << "There is a unit in your borough but you do not have enough destruction points to destroy it. " << endl;
				break;
			}
			else if (bu->get_unit_from_set(i, b) != nullptr) {
				unit = bu->get_unit_from_set(i, b);
				string build = unit->getType();
				int durability = unit->getDurability();
				string rewardT = unit->getRewardType();
				int reward = unit->getReward();
				cout << "You have in your burrough the building " << build << endl;
				cout << "Durability: " << durability << endl;
				cout << "Reward:  " << reward << " " << rewardT << endl;

				cout << "Do you wish to destroy the unit? y/n" << endl;
				string answer;
				cin >> answer;

				if (answer == "y") {
					bu->destroy_unit(unit, b);
					if (rewardT == "heal") {
						player_monster->heal(reward, player_monster);
					}
					else if (rewardT == "energy") {
						player_monster->addEnergyPoint(reward, player_monster);
					}
					else if (rewardT == "victory point")
						player_monster->addVictoryPoint(reward, player_monster);

				}
				delete unit;
				break;

			}
		}





	}

}

void player::resolveAttack(int attack, Map* m, Monsters * a[]) {



	if (position == 8 || position == 9 || position == 10)
	{
		for (int i = 0; i < 8; i++) {
			Borough* b = m->getBorough(i);
			string ennemy = b->getPlayerName();

			if (ennemy != "") {
				a[i]->damageHealth(attack, a[i]);
			}

		}

	}
	else {
		for (int i = 0; i < 3; i++) {
			Borough* b = m->getBorough(i + 8);
			string ennemy = b->getPlayerName();

			if (ennemy != "") {
				a[i]->damageHealth(attack, a[i]);
			}
		}

	}
}









void player::resolveDice(Map* m, Monsters * a[], BU* bu, Cards_Deck*  cards, player* players[]) {

	//resetting the tracking variables to 0 in order to track the proper variables of the new dice roll
	energy = 0;
	attack = 0;
	destruction = 0;
	heal = 0;
	celebrity = 0;
	ouch = 0;
	destruction_points = 0;
	//calculating how many of each is present in the dice rolls in order to know what can be done 
	for (int i = 0; i < 6; i++) {
		if (dices[i].getDiceFace() == "Energy") {
			energy += 1;
		}
		else if (dices[i].getDiceFace() == "Attack") {
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



	//handling of the energy points
	resolveEnergy(energy);
	//handling of the health points
	resolveHeal(heal);
	/*
	handling of the celebrity points*/
	resolveCelebrity(celebrity, cards, players);
	//resolving the ouch points
	resolveOuch(ouch, m, players, cards, bu);
	//resolving the destruction points
	resolveDestruction(destruction, bu, m);
	//resolving the attack points
	resolveAttack(attack, m, a);

	bool keepGoing = true;

	while (keepGoing = true) {
		cout << "You have a total of :" << endl;
		cout << energy << " Engergy" << endl;
		cout << attack << " Attack" << endl;
		cout << destruction << " Destruction" << endl;
		cout << heal << " Heal" << endl;
		cout << celebrity << " Celebrity" << endl;
		cout << ouch << " Ouch!" << endl;


		cout << "Which resolution do you wish to do? The resolution will stop once you choose to stop or once all actions have been exhausted."<< endl;
		cout << "1-Heal \n2-Ouch \n3-Attack \n4-Energy \n5-Celebrity \n6-Destruction \n7-Stop \nPlease input the corresponding number" << endl;

		string answer;

		cin >> answer;
		//verify the status of the points. when all of them reach zero no other action can take place
		if (energy == 0 && attack == 0 && destruction == 0 && heal == 0 && celebrity == 0 && ouch == 0) {
			cout << "You have no more dices to resolve. End of dice resolution" << endl;
		}
		//case 1 heal
		else if (answer =="1") {
			resolveHeal(heal);
			heal = 0;
		}
		//case 2 ouch
		else if (answer == "2") 
		{
			resolveOuch(ouch, m, players, cards, bu);
			ouch = 0;
		}
		//case 3 attack
		else if (answer == "3") {
			resolveAttack(attack, m, a);
			attack = 0;
		}
		//case 4 energy
		else if (answer == "4") {
			resolveEnergy(energy);
			energy = 0;
		}
		//case 5 celebrity
		else if (answer == "5") {
			resolveCelebrity(celebrity, cards, players);
			celebrity = 0;
		}
		//case 6 destruction
		else if (answer == "6") {
			resolveDestruction(destruction, bu, m);
			destruction = 0;
		}
		//case 7
		else if (answer == "7") {
			keepGoing = false;
			cout << "Your dice resolution is done" << endl;

		}
		//if answer is not valid
		else {
			cout << "Answer not valid. Please choose the number of the action you wish to take" << endl;
			keepGoing = true;
		}




	
	
	
	
	}







}

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
			 player_cards[i]= nullptr;
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

bool player::move1(string borough, Map* m) {
	bool statusLM = m->getBorough(8)->getBoroughStatus();
	bool statusMM = m->getBorough(9)->getBoroughStatus();
	bool statusUM = m->getBorough(10)->getBoroughStatus();
	bool isMoveSuccess=NULL;
	//cases to move to or within manhattan
	if (borough == "LowerManhattan" && statusLM == false && statusMM == false && statusUM == false) {
		//setting previous position to empty
		if (position != NULL) {
			m->setBorough(position, false, "");
		}
		//moving to new borough
		position = 8;
		m->setBorough(8, true, player_monster->getName());
		isMoveSuccess = true;
	}
	else if (borough == "MidManhattan" && position == 8) {
		m->setBorough(8, false, "");
		m->setBorough(9, true, player_monster->getName());
		position = 9;
		isMoveSuccess = true;
	}
	else if (borough == "UpperManhattan" && position == 9) {
		m->setBorough(9, false, "");
		m->setBorough(10, true, player_monster->getName());
		position = 10;
		isMoveSuccess = true;

	}


	//other boroughs
	for (int i = 0; i < 8; i++) {
		Borough * b = m->getBorough(i);
		string name = b->getBName();
		//string name = m->getBorough(i)->getBName();
		bool status = m->getBorough(i)->getBoroughStatus();
		
		 if (borough == name && status == false) {
			 if (position != NULL) {
				 m->setBorough(position, false, "");
			 }
			 position = i;
			m->setBorough(i, true, player_monster->getName());
			isMoveSuccess = true;
			break;
		
		}
		 else if(borough== name && status == true){
		cout << "This borough is full. Choose another borough or stay in your current borough" << endl;
		isMoveSuccess = false;

		 }
			
	
	}

	if (isMoveSuccess == NULL) {
		isMoveSuccess = false;
	}

	return isMoveSuccess;
}

void player::move(string borough, Map* m) {
	bool statusLM = m->getBorough(8)->getBoroughStatus();
	bool statusMM = m->getBorough(9)->getBoroughStatus();
	bool statusUM = m->getBorough(10)->getBoroughStatus();
	//cases to move to or within manhattan
	if (borough == "LowerManhattan" && statusLM == false && statusMM == false && statusUM == false) {
		//setting previous position to empty
		if (position != NULL) {
			m->setBorough(position, false, "");
		}
		//moving to new borough
		position = 8;
		m->setBorough(8, true, player_monster->getName());
		
	}
	else if (borough == "MidManhattan" && position == 8) {
		m->setBorough(8, false, "");
		m->setBorough(9, true, player_monster->getName());
		position = 9;
	}
	else if (borough == "UpperManhattan" && position == 9) {
		m->setBorough(9, false, "");
		m->setBorough(10, true, player_monster->getName());
		position = 10;

	}


	//other boroughs
	for (int i = 0; i < 8; i++) {
		string name = m->getBorough(i)->getBName();
		bool status = m->getBorough(i)->getBoroughStatus();

		if (borough == name && status == false) {
			if (position != NULL) {
				m->setBorough(position, false, "");
			}
			position = i;
			m->setBorough(i, true, player_monster->getName());
			
			break;

		}
		else {
			cout << "This borough is full. Choose another borough or stay in your current borough" << endl;
			

		}


	}

}