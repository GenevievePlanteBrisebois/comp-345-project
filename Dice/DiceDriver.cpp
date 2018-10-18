#include <iostream>
#include "Dice.h"
#include "DiceFacility.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
	DiceFacility d1;
	DiceFacility d2;

	int rand1;
	int rand2;
	int rando;
	rand1 = rand() % 5;
	rand2 = rand() % 5;
	rando = rand() % 5;

	cout << "Dice 1: " << endl;
	d1.rollDice(rand1);

	cout << "Dice 2:"<< endl;
	d2.rollDice(rand2);


	string ans;

	cout << "Would you like to reroll? y/n" << endl;
	cin >> ans;
	if (ans == "y") {
		d1.rollAgain(rando);
		cout << d2.getDiceFace();
		
	}
	
}