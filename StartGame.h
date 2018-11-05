#pragma once
#include "Player/Player/player.h"
//by Batoul Yehia 40010912
//part 1 and 2
class StartGame {
public:
	void SelectPlayers();
	~StartGame();
	StartGame();
	StartGame(player* player1, player* player2);
	StartGame(player* player1, player* player2, player* player3);
	StartGame(player* player1, player* player2, player* player3, player* player4);
	StartGame(player* player1, player* player2, player* player3, player* player4, player* player5);
	StartGame(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6);
	void SetNumPlayers(int num);
	int GetNumPlayers();
	void LoadMap();
	void BuildCards();
	void BuildBuildings();
	void BuildTokens();
};
void setPlayerOrder2(player* o[2]);
void setPlayerOrder3(player* o[3]);
void setPlayerOrder4(player* o[4]);
void setPlayerOrder5(player* o[5]);
void setPlayerOrder6(player* o[6]);
