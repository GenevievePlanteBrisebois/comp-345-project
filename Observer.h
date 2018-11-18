#pragma once
#include <string>
using namespace std;
// By: Batoul Yehia 40010912

class ObserverInterface {
public:

	int playerNum;
	int numOfPlayers;
	virtual void notifyNumberOfPlayers(int) = 0;
	virtual void notifyPlayerNumber(int) = 0;
	virtual void notifyPlayerAction(string) = 0;
	virtual void notifyCurrentBorough(string) = 0;
	
};

class Observer: public ObserverInterface {
public:
	int playerNum;
	int numOfPlayers;
	void notifyPlayerAction(string) override;
	void notifyPlayerNumber(int) override;
	void notifyCurrentBorough(string) override;
	void notifyNumberOfPlayers(int) override;
	void setPlayerNum(int playerNumber);
	void setNumPlayers(int num);
};

//for part 2

//Implement view that displays info happening in the current turn. 
//display what heasder, what step is currently being displayed.
//Ex: player 3, roll dice step
//Just display what's happening this turn.
//updated as the game goes through different players/steps to be visible at all times during gameplay

//for part 3
