#include <iostream>
#include "PlayerObserver.h"

//By Batoul Yehia
//40010912

using namespace std;

void PlayerObserver::notifyPlayerAction(string action) {
	cout << action << endl;
}

void PlayerObserver::notifyNumberOfPlayers(int i) {
	cout << "The total number of players is: " << i << endl;
}

void PlayerObserver::notifyPlayerNumber(int num) {
	cout << "Player " << num << "," << endl;
}

//void Update() {

//}