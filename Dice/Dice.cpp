#include "Dice.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


string *faceList;

string diceFace;



Dice::Dice()
{
	faceList = new string[6];
	faceList[0] = "Energy";
	faceList[1] = "Attack";
	faceList[2] = "Destruction";
	faceList[3] = "Heal";
	faceList[4] = "Celebrity";
	faceList[5] = "Ouch!";
}



void Dice::rollDice(int faceNum) {
	//srand((int)time(0));
	//int face = rand() % 5;
	//string dList[] = { "Energy", "Attack", "Destruction", "Heal", "Celebrity", "Ouch!" };
	cout << "You rolled: " << faceList[faceNum] << endl;
	setDiceFace(faceList[faceNum]);
	//return faceList[faceNum];
}

void Dice::rollAgain(int randNum, Dice d) {
	string ans;
	string done;

	cout << "Would you like to reroll " << d.getDiceFace() << "?";
	cin >> ans;
	if (ans == "y") {
		cout << "You rolled: " << faceList[randNum] << endl;
		setDiceFace(faceList[randNum]);
	}


}




void Dice::setDiceFace(string chosenFace) {
	diceFace = chosenFace;
}

string Dice::getDiceFace() {
	return diceFace;
}
Dice::~Dice()
{
	faceList = NULL;
	delete[] faceList;
}

