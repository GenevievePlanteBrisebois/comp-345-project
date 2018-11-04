#pragma once
class StartGame {
public:
	void SelectPlayers();
	//StartGame();
	~StartGame();
	StartGame(player* player1, player* player2);
	StartGame(player* player1, player* player2, player* player3);
	StartGame(player* player1, player* player2, player* player3, player* player4);
	StartGame(player* player1, player* player2, player* player3, player* player4, player* player5);
	StartGame(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6);
	void SetNumPlayers(int num);
	int GetNumPlayers();
	void LoadMap();
};