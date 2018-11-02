#pragma once
#include <string>
#include <iostream>
using namespace std;

class Dice
{
private:
	string diceList;
	string diceFace;
public:
	Dice();
	~Dice();
	void rollDice(int faceNum);
	void setDiceFace(string chosenFace);
	string getDiceFace();
};

