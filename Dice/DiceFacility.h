#pragma once
#include "Dice.h"
class DiceFacility :
	public Dice
{
public:
	DiceFacility();
	~DiceFacility();
	void rollAgain(int randNum);
};

