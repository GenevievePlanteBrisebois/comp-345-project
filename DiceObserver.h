/*
file written by Genevieve Plante-Brisebois
40003112
fall 2018 COMP 345
-----------------------------------------
This is the header for the class that will be the DiceObserver. Instead of having the update of what is rolled being hardcoded it is being changed to 
an observer pattern. When a dice is rolled it will send an update to the Observer and the Observer will display the information to the screen. 
*/

#include "Observer.h"
#include "Player/Player/player.h"
#pragma once

#include <iostream>

using namespace std;

class DiceObserver:public Observer {
public:

	DiceObserver();
	~DiceObserver();

	void roll_cout(string face, int i);

};


