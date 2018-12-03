#pragma once
#include "Player/Player/player.h"
//by Batoul Yehia 40010912
//part 1 and 2
class GameEngine {
public:
	void SelectPlayers();
	~GameEngine();
	GameEngine();
	GameEngine(player* player1, player* player2);
	GameEngine(player* player1, player* player2, player* player3);
	GameEngine(player* player1, player* player2, player* player3, player* player4);
	GameEngine(player* player1, player* player2, player* player3, player* player4, player* player5);
	GameEngine(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6);
	void SetNumPlayers(int num);
	int GetNumPlayers();
	void LoadMap();
	void BuildCards();
	void BuildBuildings();
	void BuildTokens();

	void mainLoop();
	bool loop(player* player, int turn);
	bool verifyVictory(player* player);
	bool verifyDeath(player* player);
	void chooseMonster();

	player* getPlayer2(int index);
	player* getPlayer3(int index);
	player* getPlayer4(int index);
	player* getPlayer5(int index);
	player* getPlayer6(int index);

	string getBorough(int position);


	int SelectFirst();
	void SelectOrder(int max);
};
void setPlayerOrder2(player* o[2]);
void setPlayerOrder3(player* o[3]);
void setPlayerOrder4(player* o[4]);
void setPlayerOrder5(player* o[5]);
void setPlayerOrder6(player* o[6]);



