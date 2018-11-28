#include "Observer.h"
#include <iostream>
//By Batoul Yehia 40010912
using namespace std;

int playerNum; 
int numberOfPlayers;
void Observer::notifyPlayerNumber(int num) {
	cout << "Player Number: " << num << endl;
	setPlayerNum(num);
}

void Observer::setPlayerNum(int playerNumber) {
	playerNum = playerNumber;
}

void Observer::notifyPlayerAction(string action) {
	cout << "Player Action: " << action << endl;
}

void Observer::notifyCurrentBorough(string b) {
	cout << "Currently in burough "<< b << endl;
}

void Observer::notifyNumberOfPlayers(int i) {
	cout << "The number of players is:" << i << endl;
}

void Observer::setNumPlayers(int num) {
	numberOfPlayers = num;
}

