#include <iostream>
#include <string>
#include "Player/Player/player.h"
#include "Move/Move/Move.h"
#include "BuyCardEngine/BuyCardEngine/BuyCards.h"
#include "Strategy.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Observer.h"
#include "PlayerObserver.h"

using namespace std;
Dice* strat_dices = new Dice[6];
PlayerObserver* strat_ob;

Aggressive::Aggressive() {
	strat_ob = new PlayerObserver();
}
Aggressive::~Aggressive() {
	delete strat_ob;
	strat_ob = NULL;
}

//Rolling the dice for aggressive: 
//check if attack/destruction appears 4 times.
//If not, then reroll.
void Aggressive::rollDice() {
	strat_ob->notifyPlayerAction("Aggressive Player: Rolling Dice");
	int count = 0;
	cout << "First Roll of the dices" << endl;

	for (int i = 0; i < 6; i++) {
		int face = rand() % 5;
		cout << "Dice " << i << ":  " << endl;
		strat_dices[i].rollDice(face);
	}

	/*
	for loops in order to reroll up to two times.
	*/
	for (int i = 0; i < 2; i++) {
		strat_ob->notifyPlayerAction("Aggressive Bot: Rerolling dice");
		cout << "Do you wish to reroll?" << endl;
		
		for (int i = 0; i < 6; i++) {
			if (strat_dices[i].getDiceFace() == "Attack" || strat_dices[i].getDiceFace() == "Destruction"){
				count++;
			}
		}
		if (count >= 4) {
			//if the bot has 4 or more attacks/destruction it won't reroll
			break;
		}
		
		if (count < 4) {
			cout << "We will now check which dices you wish to reroll.";

			for (int j = 0; j < 6; j++) {
				cout << "Do you wish to reroll dice " << j << " y/n ?";
				//string answer;
				//cin >> answer;
				if (strat_dices[j].getDiceFace() == "Attack" || strat_dices[j].getDiceFace()=="Destruction") {
					break;
				}
				else {
					int face2 = rand() % 5;
					strat_dices[j].rollDice(face2);
				}
			}

			//if it was the final roll
			if (i == 1) {
				cout << "After final rolling of the dices these are your dices:" << endl;

				for (int j = 0; j < 6; j++) {
					cout << strat_dices[j].getDiceFace() << endl;
				}

			}
			//if it was the second roll
			else if (i == 0) {

				cout << "After rolling for a second time these are your dices:" << endl;

				for (int j = 0; j < 6; j++) {
					cout << strat_dices[j].getDiceFace() << endl;
				}
				cout << "You can still reroll your dices one time. " << endl;
			}
		}
		//breaking the for loop in the case that the player decides against rerolling
		else
			break;
	}
}

void Aggressive::resolveDice() {
	strat_ob->notifyPlayerAction("Aggressive player resolving Dice");
}

void Aggressive::move() {
	strat_ob->notifyPlayerAction("Aggressive player moving");
}

void Aggressive::buyCards() {
	strat_ob->notifyPlayerAction("Aggressive player buying cards");
}


void Moderate::rollDice() {
	strat_ob->notifyPlayerAction("Moderate player rolling dice");
}

void Moderate::resolveDice() {
	strat_ob->notifyPlayerAction("Moderate player resolving dice");
}

void Moderate::move() {
	strat_ob->notifyPlayerAction("Moderate player moving");
}

void Moderate::buyCards() {
	strat_ob->notifyPlayerAction("Moderate player buying cards");
}


