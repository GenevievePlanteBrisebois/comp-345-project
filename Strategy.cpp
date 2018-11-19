#include <iostream>
#include <string>
#include "Player/Player/player.h"
#include "Move/Move/Move.h"
#include "BuyCardEngine/BuyCardEngine/BuyCards.h"
#include "Strategy.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Observer.h"

using namespace std;
Dice* dices = new Dice[6];
Observer* ob;

Aggressive::Aggressive() {
	ob = new Observer();
}
Aggressive::~Aggressive() {
	delete ob;
	ob = NULL;
}

//Rolling the dice for aggressive: 
//check if attack/destruction appears 4 times.
//If not, then reroll.
void Aggressive::rollDice() {
	ob->notifyPlayerAction("Aggressive Player: Rolling Dice");
	int count = 0;
	cout << "First Roll of the dices" << endl;

	for (int i = 0; i < 6; i++) {
		int face = rand() % 5;
		cout << "Dice " << i << ":  " << endl;
		dices[i].rollDice(face);
	}

	/*
	for loops in order to reroll up to two times.
	*/
	for (int i = 0; i < 2; i++) {
		ob->notifyPlayerAction("Aggressive Bot: Rerolling dice");
		cout << "Do you wish to reroll?" << endl;
		
		for (int i = 0; i < 6; i++) {
			if (dices[i].getDiceFace() == "Attack" || dices[i].getDiceFace() == "Destruction"){
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
				if (dices[j].getDiceFace == "Attack" || dices[j].getDiceFace()=="Destruction") {
					break;
				}
				else {
					int face2 = rand() % 5;
					dices[j].rollDice(face2);
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

void Aggressive::resolveDice() {
	ob->notifyPlayerAction("Aggressive player resolving Dice");
}

void Aggressive::move() {
	ob->notifyPlayerAction("Aggressive player moving");
}

void Aggressive::buyCards() {
	ob->notifyPlayerAction("Aggressive player buying cards");
}


void Moderate::rollDice() {
	ob->notifyPlayerAction("Moderate player rolling dice");
}

void Moderate::resolveDice() {
	ob->notifyPlayerAction("Moderate player resolving dice");
}

void Moderate::move() {
	ob->notifyPlayerAction("Moderate player moving");
}

void Moderate::buyCards() {
	ob->notifyPlayerAction("Moderate player buying cards");
}


