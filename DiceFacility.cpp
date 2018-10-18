#include "DiceFacility.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Dice *d0;

DiceFacility::DiceFacility()
{
	Dice *d0 = new Dice();
}


DiceFacility::~DiceFacility()
{
	delete d0;
	d0 = NULL;
}

void DiceFacility::rollAgain(int randNum) {
	string ans;
	string done;

	//cout << "Would you like to roll again? y/n" << endl;
	//cin >> ans;
	//if (ans == "y") {
		 
			cout << "Would you like to reroll " << d0->getDiceFace() << "?";
			cin >> ans;
			if (ans == "y") {
				srand((int)time(0));
				d0->rollDice(randNum);
			}
	//}
	
}