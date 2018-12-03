/*
file written by Genevieve PLante-Brisebois
40003112

FALL 2018
COMP345

----------------
Dice Observer class implementation. Look at .h file to get summary of expected behavior. 


*/


#include "DiceObserver.h"
#include "Player/Player/player.h"
#include "Observer.h"

#include <iostream>

using namespace std;

DiceObserver::DiceObserver() {

}
DiceObserver::~DiceObserver() {

}

void DiceObserver::roll_cout(string face, int i) {
	cout << "Rolling dice: " << i << endl;
	cout << "You have rolled: " << face << endl;
}

void DiceObserver::roll_order(string face) {

	cout << face << endl;
}
