//A2 part1 and part2

//Written by Batoul Yehia 40010912

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
BU* bu;
Cards_Deck* deck;
Dice* d;
player* players2[2];
player* players3[3];
player* players4[4];
player* players5[5];
player* players6[6];
//player* playerArray[numPlayers];

Cards_Deck* deck;

StartGame::StartGame(player* player1, player* player2) {
	p1 = player1;
	p2 = player2;

	//create an array of players
	players2[2] = new player();


}

StartGame::StartGame(player* player1, player* player2, player* player3) {
	p1 = player1;
	p2 = player2;
	p3 = player3;

	players3[3] = new player();

}

StartGame::StartGame(player* player1, player* player2, player* player3, player* player4) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;

	players4[4] = new player();
}


StartGame::StartGame(player* player1, player* player2, player* player3, player* player4, player* player5) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;

	players5[5] = new player();

}
StartGame::StartGame(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;
	p6 = player6;

	players6[6] = new player();
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
	deck = NULL;
	bu = NULL;
	d = NULL;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete deck;
	delete bu;
	delete d;
}
//create the cards
void BuildCards() {
	deck = new Cards_Deck();
}
void BuildTokens() {
	//build tokens
	Tokens* token = new Tokens();
	Tokens* carapace[15];
	for (int i = 0; i < 15; i++) {
		carapace[i] = token->create_carapace();
	}
	
	Tokens* souvenir[5];
	for (int i = 0; i < 5; i++) {
		souvenir[i] - token->create_souvenir();
	}

	Tokens* web[13];
	for (int i = 0; i < 13; i++) {
		web[i] = token->create_web();
	}

	Tokens* jinx[13];
	for (int i = 0; i < 13; i++) {
		jinx[i] = token->create_jinx();
	}
}

void BuildBuildings() {
	//build buildings
	bu = new BU();
	bu->build_building_deck();
	bu->shuffle(); //shuffle them
}

int SelectFirst() {
	d = new Dice();
	string face;
	int temp1 = 0;
	int max = 0;
	int count = 0;
	for (int i = 0; i < numPlayers; i++) {
		cout << "Player " << (i + 1) << "dice: ";
		for (int j = 0; j < 8; j++) { //roll dice 8 times
			d->rollDice(rand() % 5);
			face = d->getDiceFace;
			if (face == "Attack") {
				count++;
			}
		}
		if (count > temp1) {
			max = i + 1;
			temp1 = count;
		}
		//max is the Player number that gets to play first
	}

	cout << "First turn goes to Player " << max << endl;
	
	return max;
	}

void SelectOrder(int max) {
	cout << "Here is now the order of the players: " << endl;

	switch (numPlayers) {
	case 2:
		player* order[2];
		if (max == 1) {
			order[0] = p1;
			order[1] = p2;
		}
		if (max == 2) {
			order[0] = p2;
			order[1] = p1;
		}
		setPlayerOrder2(order);
		break;
	case 3:
		player* order[3];
		if (max == 1) {
			order[0] = p1;
			order[1] = p2;
			order[2] = p3;
		}
		if (max == 2) {
			order[0] = p2;
			order[1] = p1;
			order[2] = p3;
		}
		if (max == 3) {
			order[0] = p3;
			order[1] = p1;
			order[2] = p2;
		}
		setPlayerOrder3(order);
		break;
	case 4:
		player* order[4];
		if (max == 1) {
			order[0] = p1;
			order[1] = p2;
			order[2] = p3;
			order[3] = p4;
		}
		if (max == 2) {
			order[0] = p2;
			order[1] = p1;
			order[2] = p3;
			order[3] = p4;
		}
		if (max == 3) {
			order[0] = p3;
			order[1] = p1;
			order[2] = p2;
			order[3] = p4;
		}
		if (max == 4) {
			order[0] = p4;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
		}
		setPlayerOrder4(order);
		break;
	case 5:
		player* order[5];
		if (max == 1) {
			order[0] = p1;
			order[1] = p2;
			order[2] = p3;
			order[3] = p4;
			order[4] = p5;
		}
		if (max == 2) {
			order[0] = p2;
			order[1] = p1;
			order[2] = p3;
			order[3] = p4;
			order[4] = p5;
		}
		if (max == 3) {
			order[0] = p3;
			order[1] = p1;
			order[2] = p2;
			order[3] = p4;
			order[4] = p5;
		}
		if (max == 4) {
			order[0] = p4;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
			order[4] = p5;
		}
		if (max == 5) {
			order[0] = p5;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
			order[4] = p4;
		}
		setPlayerOrder5(order);
		break;
	case 6:
		player* order[6];
		if (max == 1) {
			order[0] = p1;
			order[1] = p2;
			order[2] = p3;
			order[3] = p4;
			order[4] = p5;
			order[5] = p6;

		}
		if (max == 2) {
			order[0] = p2;
			order[1] = p1;
			order[2] = p3;
			order[3] = p4;
			order[4] = p5;
			order[5] = p6;
		}
		if (max == 3) {
			order[0] = p3;
			order[1] = p1;
			order[2] = p2;
			order[3] = p4;
			order[4] = p5;
			order[5] = p6;
		}
		if (max == 4) {
			order[0] = p4;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
			order[4] = p5;
			order[5] = p6;
		}
		if (max == 5) {
			order[0] = p5;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
			order[4] = p4;
			order[5] = p6;
		}
		if (max == 6) {
			order[0] = p6;
			order[1] = p1;
			order[2] = p2;
			order[3] = p3;
			order[4] = p4;
			order[5] = p5;
		}
		setPlayerOrder6(order);
		break;

	}
}


	void setPlayerOrder2(player* o[2]) {
		for (int i = 0; i < 2; i++) {
			players2[i] = o[i];
		}
	}
	void setPlayerOrder3(player* o[3]) {
		for (int i = 0; i < 3; i++) {
			players3[i] = o[i];
		}

	}
	void setPlayerOrder4(player* o[4]) {
		for (int i = 0; i < 4; i++) {
			players4[i] = o[i];
		}
	}
	void setPlayerOrder5(player* o[5]){
		for (int i = 0; i < 5; i++) {
			players5[i] = o[i];
		}
	}
	void setPlayerOrder6(player* o[6]) {
		for (int i = 0; i < 6; i++) {
			players6[i] = o[i];
		}
	}





