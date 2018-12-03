#pragma once
#include <iostream>
#include "Observer.h"

class PlayerObserver : public Observer {
public:
	void notifyPlayerNumber(int num);
	void notifyPlayerAction(string action);
	void notifyNumberOfPlayers(int i);
	
};

