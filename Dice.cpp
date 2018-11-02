#include "Dice.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string *diceList;

string diceFace; 

Dice::Dice()
{
	diceList = new string[6];
	diceList[0] = "Energy";
	diceList[1] = "Attack";
	diceList[2] = "Destruction";
	diceList[3] = "Heal";
	diceList[4] = "Celebrity";
	diceList[5] = "Ouch!";

}

Dice::~Dice()
{
	diceList = NULL;
	delete[] diceList;
}

string Dice::rollDice(int faceNum) {
	srand((int)time(0));
	//int face = rand() % 5;
	cout << "You rolled: " << diceList[faceNum] << endl;
	setDiceFace(diceList[faceNum]);
	return diceList[faceNum];
}

void Dice::setDiceFace(string chosenFace) {
	diceFace = chosenFace;
}

string Dice::getDiceFace() {
	return diceFace;
}