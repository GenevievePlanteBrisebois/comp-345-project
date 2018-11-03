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

	cout << "You rolled: " << faceList[faceNum] << endl;
	setDiceFace(faceList[faceNum]);

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