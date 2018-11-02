#include <iostream>
#include "Dice.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {

	srand((int)time(0));
	Dice d1;
	Dice d2;


	cout << "Dice 1:" << endl;
	d1.rollDice(rand() % 5);
	cout << "Dice 2:" << endl;
	d2.rollDice(rand() % 5);

	
	cout << "Would you like to reroll "<< d1.getDiceFace() << "? y/n" <<endl;
	string ans;
	cin >> ans;
	if (ans == "y") {
		d1.rollDice(rand() % 5);
	}

	cout << "Would you like to reroll " << d2.getDiceFace() << "? y/n" << endl;
	cin >> ans;
	if (ans == "y") {
		d2.rollDice(rand() % 5);
	}


}