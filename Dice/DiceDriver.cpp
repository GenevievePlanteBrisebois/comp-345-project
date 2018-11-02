#include <iostream>
#include "Dice.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {

	srand((int)time(0));
	Dice d1;
	Dice d2;
	Dice d3;
	Dice d4;

	int rand1;
	int rand2;
	int rando;
	rand1 = rand() % 5;
	rand2 = rand() % 5;
	rando = rand() % 5;


	cout << "Dice 1: " << endl;
	d1.rollDice(rand1);

	cout << "Dice 2:" << endl;
	d2.rollDice(rand2);

	cout << "Dice 3:" << endl;
	d3.rollDice(rand() % 5);

	cout << "Dice 4:" << endl;
	d4.rollDice(rand() % 5);



	string ans;

	d1.rollDice(rand() % 5);

	d1.rollDice(rand() % 5);

	d1.rollDice(rand() % 5);

	d1.rollDice(rand() % 5);


	d2.rollDice(rand() % 5);


	d2.rollDice(rand() % 5);
	cout << d2.getDiceFace();
	cout << "Would you like to reroll? y/n" << endl;
	cin >> ans;
	if (ans == "y") {
		cout << "Would you like to reroll " << d1.getDiceFace() << "?" << endl;
		cin >> ans;
		if (ans == "y") {
			//d1.rollAgain(rand() % 5, d1);
			d1.rollAgain(rand() % 5, d2);
		}
		cout << "Would you like to reroll " << d2.getDiceFace() << "?" << endl;
		cin >> ans;
		if (ans == "y") {
			d2.rollAgain(rand() % 5, d2);
		}
	}

}