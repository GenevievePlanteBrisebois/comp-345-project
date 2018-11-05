/*
Part 1: Game start
Provide a group of C++ classes that implements a user interaction mechanism to start the game by allowing
the player to:
1) Select a map from a list of files as stored in a directory.
2) Select the number of players in the game (2-6 players).
The code should load all the game pieces and use the map loader to load the selected and appropriate map,
create all the players, assign dice rolling facilities to the players, create a deck of cards, and assign an empty
hand of cards to each player.
You must deliver a driver that demonstrates that 1) different valid maps can be loaded and their validity is
verified (i.e. it is a connected graph, etc.), and invalid maps are rejected without the program crashing; 2)
the right number of players is created, a deck with the right number of cards is created.
*/
#include <iostream>
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Cards\Tokens.h"
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Dice\Dice.h"
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Map Implementation\Map.h"
#include "C:\Users\leb_b\Github\comp345-kingsOfNY\Player\Player\player.h"
#include <string>
#include "StartGame.h"
#include <fstream>

using namespace std;

int numPlayers;
player* p1;
player* p2;
player* p3;
player* p4;
player* p5;
player* p6;


Cards_Deck* deck;

StartGame::StartGame(player* player1, player* player2) {
	p1 = player1;
	p2 = player2;

	deck = new Cards_Deck();


}

StartGame::StartGame(player* player1, player* player2, player* player3) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
}

StartGame::StartGame(player* player1, player* player2, player* player3, player* player4) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
}


StartGame::StartGame(player* player1, player* player2, player* player3, player* player4, player* player5) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;

}
StartGame::StartGame(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;
	p6 = player6;
}
void StartGame::SelectPlayers() {
	player* p1 = new player();
	player* p2 = new player();
	player* p3 = new player();
	player* p4 = new player();
	player* p5 = new player();
	player* p6 = new player();
	int num;


	cout << "Let us start the game." << endl;
	cout << "Select number of players (2-6)" << endl;
	cin >> num;
	switch (num) {
	case 2:
		StartGame(p1, p2);
		SetNumPlayers(2);
		break;
	case 3:
		//creates three players
		StartGame(p1, p2, p3);
		SetNumPlayers(3);
		break;

	case 4:
		//creates four players
		StartGame(p1, p2, p3, p4);
		SetNumPlayers(4);
		break;
	case 5:
		//creates five players
		StartGame(p1, p2, p3, p4, p5);
		SetNumPlayers(5);
		break;
	case 6:
		//creates six players

		StartGame(p1, p2, p3, p4, p5, p6);
		SetNumPlayers(6);
		break;
	}


}

void StartGame::SetNumPlayers(int num) {
	numPlayers = num;
}

int StartGame::GetNumPlayers() {
	return numPlayers;
}
void StartGame::LoadMap() {
	string chosenMap;
	string line;
	int count;

	cout << "Please select one of the following map files: " << endl;
	//idk somehow shows directory
	cin >> chosenMap;

	//read in the file to get number of lines
	ifstream file(chosenMap);
	while (getline(file, line)) {
		count++;
	}

	Map m(count); //create the map object
	m.mapLoader(chosenMap); //loads map here
}
StartGame::~StartGame() {
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	p4 = NULL;
	p5 = NULL;
	p6 = NULL;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
}


