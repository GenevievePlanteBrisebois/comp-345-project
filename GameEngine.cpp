//A2 part1 and part2

//Written by Batoul Yehia 40010912

#include <iostream>
#include "..\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "..\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "..\comp345-kingsOfNY\Cards\Tokens.h"
#include "..\comp345-kingsOfNY\Dice\Dice.h"
#include "..\comp345-kingsOfNY\Map Implementation\Map.h"
#include "..\comp345-kingsOfNY\Player\Player\player.h"
#include "Move/Move/Move.h"
#include "BuyCardEngine/BuyCardEngine/BuyCards.h"
#include "..\comp345-kingsOfNY\Observer.h"
#include "StatsObserver.h"


#include <string>
#include "GameEngine.h"
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
Observer* ob;
StatsObserver* statOb = new StatsObserver();

Map* m;

Move* moveEngine = new Move();
BuyCards* buyCards = new BuyCards();

//player* playerArray[numPlayers];


//constructor for two players
GameEngine::GameEngine(player* player1, player* player2) {
	p1 = player1;
	p2 = player2;

	//create an array of players
	players2[2] = new player();
	ob = new Observer();

}

//constructor for three players
GameEngine::GameEngine(player* player1, player* player2, player* player3) {
	p1 = player1;
	p2 = player2;
	p3 = player3;

	players3[3] = new player();
	ob = new Observer();

}

//constructor for four players
GameEngine::GameEngine(player* player1, player* player2, player* player3, player* player4) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;

	players4[4] = new player();
	ob = new Observer();
}

//contructor for five players
GameEngine::GameEngine(player* player1, player* player2, player* player3, player* player4, player* player5) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;

	players5[5] = new player();
	ob = new Observer();

}

//constructor for six players
GameEngine::GameEngine(player* player1, player* player2, player* player3, player* player4, player* player5, player* player6) {
	p1 = player1;
	p2 = player2;
	p3 = player3;
	p4 = player4;
	p5 = player5;
	p6 = player6;

	players6[6] = new player();
	ob = new Observer();
}

GameEngine::GameEngine() {
	//default constructor
}

void GameEngine::SelectPlayers() {
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
		GameEngine(p1, p2);
		
		break;
	case 3:
		//creates three players
		GameEngine(p1, p2, p3);
	
		break;

	case 4:
		//creates four players
		GameEngine(p1, p2, p3, p4);
	
		break;
	case 5:
		//creates five players
		GameEngine(p1, p2, p3, p4, p5);

		break;
	case 6:
		//creates six players
		GameEngine(p1, p2, p3, p4, p5, p6);
		
		break;
	}
	SetNumPlayers(num);
	ob->notifyNumberOfPlayers(num);

}

void GameEngine::SetNumPlayers(int num) {
	numPlayers = num;
}

int GameEngine::GetNumPlayers() {
	return numPlayers;
}
void GameEngine::LoadMap() {
	string chosenMap;
	string line;
	int count=0;

	cout << "Please select one of the following map files: " << endl;
	
	cin >> chosenMap;
	//pick map.txt
	//read in the file to get number of lines
	ifstream file(chosenMap);
	while (getline(file, line)) {
		count++;
	}

	m = m(count) //create the map object
	m->mapLoader(chosenMap); //loads map here
}
GameEngine::~GameEngine() {
	p1 = NULL;
	p2 = NULL;
	p3 = NULL;
	p4 = NULL;
	p5 = NULL;
	p6 = NULL;
	deck = NULL;
	bu = NULL;
	d = NULL;
	moveEngine = NULL;
	buyCards = NULL;
	ob = NULL;
	statOb = NULL;
	delete[] * players2;
	delete[] * players3;
	delete[] * players4;
	delete[] * players5;
	delete[] * players6;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete deck;
	delete bu;
	delete d;
	delete moveEngine;
	delete buyCards;
	delete ob;
	delete statOb;
}
//create the cards
void GameEngine::BuildCards() {
	deck = new Cards_Deck();
}
void GameEngine::BuildTokens() {
	//build tokens
	Tokens* token = new Tokens();
	Tokens* carapace[15];
	for (int i = 0; i < 15; i++) {
		carapace[i] = token->create_carapace();
	}
	
	Tokens* souvenir[5];
	for (int i = 0; i < 5; i++) {
		souvenir[i] = token->create_souvenir();
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

void GameEngine::BuildBuildings() {
	//build buildings
	bu = new BU();
	bu->build_building_deck();
	bu->shuffle(); //shuffle them
}

//function that checks which player rolls the most Attacks
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
			face = d->getDiceFace();
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

//selects the order of the players based on which player starts
void SelectOrder(int max) {
	cout << "Here is now the order of the players: " << endl;

	switch (numPlayers) {
	case 2:
		player* orderTwo[2];
		if (max == 1) { //if player 1 got the the most attacks, they start first
			orderTwo[0] = p1;
			orderTwo[1] = p2;
		}
		if (max == 2) { //if player 2 got the most attacks, they start first
			orderTwo[0] = p2;
			orderTwo[1] = p1;
		}
		setPlayerOrder2(orderTwo); //set the order of the players based on what is given
		break;
	case 3:
		player* orderThree[3];
		if (max == 1) {
			orderThree[0] = p1;
			orderThree[1] = p2;
			orderThree[2] = p3;
		}
		if (max == 2) {
			orderThree[0] = p2;
			orderThree[1] = p1;
			orderThree[2] = p3;
		}
		if (max == 3) {
			orderThree[0] = p3;
			orderThree[1] = p1;
			orderThree[2] = p2;
		}
		setPlayerOrder3(orderThree);
		break;
	case 4:
		player* orderFour[4];
		if (max == 1) {
			orderFour[0] = p1;
			orderFour[1] = p2;
			orderFour[2] = p3;
			orderFour[3] = p4;
		}
		if (max == 2) {
			orderFour[0] = p2;
			orderFour[1] = p1;
			orderFour[2] = p3;
			orderFour[3] = p4;
		}
		if (max == 3) {
			orderFour[0] = p3;
			orderFour[1] = p1;
			orderFour[2] = p2;
			orderFour[3] = p4;
		}
		if (max == 4) {
			orderFour[0] = p4;
			orderFour[1] = p1;
			orderFour[2] = p2;
			orderFour[3] = p3;
		}
		setPlayerOrder4(orderFour);
		break;
	case 5:
		player* orderFive[5];
		if (max == 1) {
			orderFive[0] = p1;
			orderFive[1] = p2;
			orderFive[2] = p3;
			orderFive[3] = p4;
			orderFive[4] = p5;
		}
		if (max == 2) {
			orderFive[0] = p2;
			orderFive[1] = p1;
			orderFive[2] = p3;
			orderFive[3] = p4;
			orderFive[4] = p5;
		}
		if (max == 3) {
			orderFive[0] = p3;
			orderFive[1] = p1;
			orderFive[2] = p2;
			orderFive[3] = p4;
			orderFive[4] = p5;
		}
		if (max == 4) {
			orderFive[0] = p4;
			orderFive[1] = p1;
			orderFive[2] = p2;
			orderFive[3] = p3;
			orderFive[4] = p5;
		}
		if (max == 5) {
			orderFive[0] = p5;
			orderFive[1] = p1;
			orderFive[2] = p2;
			orderFive[3] = p3;
			orderFive[4] = p4;
		}
		setPlayerOrder5(orderFive);
		break;
	case 6:
		player* orderSix[6];
		if (max == 1) {
			orderSix[0] = p1;
			orderSix[1] = p2;
			orderSix[2] = p3;
			orderSix[3] = p4;
			orderSix[4] = p5;
			orderSix[5] = p6;

		}
		if (max == 2) {
			orderSix[0] = p2;
			orderSix[1] = p1;
			orderSix[2] = p3;
			orderSix[3] = p4;
			orderSix[4] = p5;
			orderSix[5] = p6;
		}
		if (max == 3) {
			orderSix[0] = p3;
			orderSix[1] = p1;
			orderSix[2] = p2;
			orderSix[3] = p4;
			orderSix[4] = p5;
			orderSix[5] = p6;
		}
		if (max == 4) {
			orderSix[0] = p4;
			orderSix[1] = p1;
			orderSix[2] = p2;
			orderSix[3] = p3;
			orderSix[4] = p5;
			orderSix[5] = p6;
		}
		if (max == 5) {
			orderSix[0] = p5;
			orderSix[1] = p1;
			orderSix[2] = p2;
			orderSix[3] = p3;
			orderSix[4] = p4;
			orderSix[5] = p6;
		}
		if (max == 6) {
			orderSix[0] = p6;
			orderSix[1] = p1;
			orderSix[2] = p2;
			orderSix[3] = p3;
			orderSix[4] = p4;
			orderSix[5] = p5;
		}
		setPlayerOrder6(orderSix);
		break;

	}
}

//Different setOrder functions based on the number of players
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

	void GameEngine::chooseMonster() {
	
		string chosen;
		Active_Monsters* active = new Active_Monsters();
		//different cases for different number of players
		switch (numPlayers) {
		case 2:
			for (int i = 0; i < 2; i++) {
				ob->notifyPlayerAction("Choosing monsters");
				ob->notifyPlayerNumber(i);
				cout << "Monsters to choose from are: " << endl;
				cout << "Mantis \nCaptain Fish \nDragonis \nKong \nSheriff\nRob" << endl;

				cout << "Player " << i + 1 << "Please pick a monster.";
				cin >> chosen;
				//create a new monster with what the player picked
				Monsters* monsterChosen = new Monsters(chosen);
				//active.addActive(monsterChosen);
				players2[i]->setMonster(monsterChosen);

			}
			break;
		case 3:
			for (int i = 0; i < 3; i++) {
				ob->notifyPlayerAction("Choosing monsters");
				ob->notifyPlayerNumber(i);
				cout << "Monsters to choose from are: " << endl;
				cout << "Mantis \nCaptain Fish \nDragonis \nKong \nSheriff\nRob" << endl;

				cout << "Player " << i + 1 << "Please pick a monster.";
				cin >> chosen;
				Monsters* monsterChosen = new Monsters(chosen);
				//active.addActive(monsterChosen);
				players3[i]->setMonster(monsterChosen);
			}
			break;
		case 4:
			for (int i = 0; i < 4; i++) {
				ob->notifyPlayerAction("Choosing monsters");
				ob->notifyPlayerNumber(i);
				cout << "Monsters to choose from are: " << endl;
				cout << "Mantis \nCaptain Fish \nDragonis \nKong \nSheriff\nRob" << endl;

				cout << "Player " << i + 1 << "Please pick a monster.";
				cin >> chosen;
				Monsters* monsterChosen = new Monsters(chosen);
				//active.addActive(monsterChosen);
				players4[i]->setMonster(monsterChosen);
			}
			break;
		case 5:
			for (int i = 0; i < 5; i++) {
				ob->notifyPlayerAction("Choosing monsters");
				ob->notifyPlayerNumber(i);
				cout << "Monsters to choose from are: " << endl;
				cout << "Mantis \nCaptain Fish \nDragonis \nKong \nSheriff\nRob" << endl;

				cout << "Player " << i + 1 << "Please pick a monster.";
				cin >> chosen;
				Monsters* monsterChosen = new Monsters(chosen);
				//active.addActive(monsterChosen);
				players5[i]->setMonster(monsterChosen);
			}
			break;
		case 6:
			for (int i = 0; i < 6; i++) {
				ob->notifyPlayerAction("Choosing monsters");
				ob->notifyPlayerNumber(i);
				cout << "Monsters to choose from are: " << endl;
				cout << "Mantis \nCaptain Fish \nDragonis \nKong \nSheriff\nRob" << endl;

				cout << "Player " << i + 1 << "Please pick a monster.";
				cin >> chosen;
				Monsters* monsterChosen = new Monsters(chosen);
				//active.addActive(monsterChosen);
				players6[i]->setMonster(monsterChosen);
			}
			break;
		}
	}

	bool GameEngine::verifyVictory(player* player) {
	int vp=	player->getMonster()->getVictoryPoint();
	bool victory;
	bool onlySurvivor;
	bool dead;
	int numOfDead = 0;
	//cases depending on the number of players to see if the player is the only survivor
	if (numPlayers == 2) {
		for (int i = 0; i < 2; i++) {
			dead = verifyDeath(players2[i]);
			if (dead == true && players2[i] != player) {
				onlySurvivor = true;
			}
			}
	}
	else if (numPlayers == 3) {
		for (int i = 0; i < 3; i++) {
			dead = verifyDeath(players3[i]);
			if (dead == true && players3[i] != player) {
				numOfDead++;
			}
		}
		dead = verifyDeath(player);
		if (dead == false && numOfDead == 2) {
			onlySurvivor = true;
		}
	
	}
	else if (numPlayers == 4) {
		for (int i = 0; i < 4; i++) {
			dead = verifyDeath(players4[i]);
			if (dead == true && players4[i] != player) {
				numOfDead++;
			}
		}
		dead = verifyDeath(player);
		if (dead == false && numOfDead == 3) {
			onlySurvivor = true;
		}

	}
	else if (numPlayers == 5) {
		for (int i = 0; i < 5; i++) {
			dead = verifyDeath(players5[i]);
			if (dead == true && players5[i] != player) {
				numOfDead++;
			}
		}
		dead = verifyDeath(player);
		if (dead == false && numOfDead == 4) {
			onlySurvivor = true;
		}

	}
	else if (numPlayers == 6) {
		for (int i = 0; i < 6; i++) {
			dead = verifyDeath(players6[i]);
			if (dead == true && players6[i] != player) {
				numOfDead++;
			}
		}
		dead = verifyDeath(player);
		if (dead == false && numOfDead == 5) {
			onlySurvivor = true;
		}

	}

	//checking the victory criterias, either only survivor either 20 vp

	if (vp >= 20) {
		victory = true;
	}
	else if (onlySurvivor == true)
		victory = true;
	else
		victory = false;
	return victory;

	}

	bool GameEngine::verifyDeath(player* players) {
	
		bool dead;
		int health = players->getMonster()->getHealth();

		if (health <= 0)
			dead = true;
		else
			dead = false;
		return dead;
	
	
	}



	//returns false if victory not obtained
	bool GameEngine::loop(player* p, int turn) {
		//if the player is dead it will exit the loop right away and move on to the next player. 
		if (verifyDeath(p) == true) {
		 bool dead = false;
		 return dead;
		}
		//place the players on the map if it is the first turn. 
		else if (turn == 1) {
			//make a while loop to make sure the player is placed on the map and then use the move1(string borough, Map* m) function to move the player
			//the move1()  function will allow to move the player in a borough and will return false if the move was failed. 
			cout << "It is now time to place your monsters on the map before we start playing. You ca place yourself anywhere on the map but on the island of Manhattan" << endl;
			cout << "There are four boroughs in which you can go" << endl;
			cout << "Please choose one of the following borroughs. Input the number. \n1-Staten Island \n2-Bronx \n3-Queens \n4-Brooklyn" << endl;
			
			bool loop = false;
			while (loop == false) {
				string answer;
			cin >> answer;


			if (answer == "1") {
				loop=p->move1("StatenIsland", m);
			}
			else if (answer == "2") {
				loop = p->move1("Bronx", m);
			}
			else if (answer == "3") {
				loop = p->move1("Queens", m);
			
			}
			else if (answer == "4") {
				loop = p->move1("Brooklyn", m);
			}
			
			}

		}
		else {
			statOb->displayStats();
			//dice rolling
			p->rollDice();
			//dice resolution
			if (numPlayers == 2)
				p->resolveDice(m, a, bu, deck, players2);
			else if (numPlayers == 3)
				p->resolveDice(m, a, bu, deck, players3);
			else if (numPlayers == 4)
				p->resolveDice(m, a, bu, deck, players4);
			else if (numPlayers == 5)
				p->resolveDice(m, a, bu, deck, players5);
			else if (numPlayers == 6)
				p->resolveDice(m, a, bu, deck, players6);
			statOb->displayStats();
			//moving
			
				moveEngine->move(p, m);
			
			//buy cards 
			cout << "Do you wish to buy a card? y/n" << endl;
			string answer;
			if (answer == "y") {
				buyCards.buyCards(p);
			}
			//verification if anyone died or if anyone has won
			if (numPlayers == 2)
			{
				for (int i = 0; i < 2; i++) {
					if (verifyDeath(players2[i]) == true) {
						players2[i]->getMonster()->setHealth(0);
						players2[i]->getMonster()->setEnergy(0);
					}
					if (verifyVictory(players2[i]) == true) {
						bool winner = true;
						cout << "Congratulations You have won" << players2[i]->getMonster()->getName() << endl;
						return winner;
					}
					else
						return false;
				}

			}
			else if (numPlayers == 3) {
				for (int i = 0; i < 3; i++) {
					if (verifyDeath(players3[i]) == true) {
						players3[i]->getMonster()->setHealth(0);
						players3[i]->getMonster()->setEnergy(0);
					}
					if (verifyVictory(players3[i]) == true) {
						bool winner = true;
						ob->notifyPlayerAction("Winning");
						cout << "Congratulations You have won" << players3[i]->getMonster()->getName() << endl;
						return winner;
					}
					else
						return false;
				}
			}
			else if (numPlayers == 4) {
				for (int i = 0; i < 4; i++) {
					if (verifyDeath(players4[i]) == true) {
						players4[i]->getMonster()->setHealth(0);
						players4[i]->getMonster()->setEnergy(0);
					}
					if (verifyVictory(players4[i]) == true) {
						bool winner = true;
						ob->notifyPlayerAction("Winning");
						cout << "Congratulations You have won" << players4[i]->getMonster()->getName() << endl;
						return winner;
					}
					else
						return false;
				}

			}
			else if (numPlayers == 5) {
				for (int i = 0; i < 5; i++) {
					if (verifyDeath(players5[i]) == true) {
						players5[i]->getMonster()->setHealth(0);
						players5[i]->getMonster()->setEnergy(0);
					}
					if (verifyVictory(players5[i]) == true) {
						bool winner = true;
						ob->notifyPlayerAction("Winning");
						cout << "Congratulations You have won" << players5[i]->getMonster()->getName() << endl;
						return winner;
					}
					else
						return false;
				}
			}
			else if (numPlayers == 6) {
				for (int i = 0; i < 6; i++) {
					if (verifyDeath(players6[i]) == true) {
						players6[i]->getMonster()->setHealth(0);
						players6[i]->getMonster()->setEnergy(0);
					}
					if (verifyVictory(players6[i]) == true) {
						bool winner = true;
						ob->notifyPlayerAction("Winning");
						cout << "Congratulations You have won" << players6[i]->getMonster()->getName() << endl;
						return winner;
					}
					else
						return false;
				}
			}
		}
	}

	//up to 6 players 
	void GameEngine::mainLoop() {
		bool winner;
		bool keepGoing = true;
		int turn = 1;
		while (keepGoing = true) {
			//the different cases of different number of players
			if (numPlayers == 2) {
				for (int i = 0; i < 2; i++) {
					winner = loop(players2[i], turn);//ake the loop for one players turn
					if (winner = true) {
						keepGoing = false; //to stop the while loop and end the game
						break; //to break the for loop
					}
				}
				
				turn++;//increment the turn. will also allow to track things if ever we want to keep track of it. 
			}
			else if (numPlayers == 3) {
				for (int i = 0; i < 4; i++) {
					winner = loop(players3[i], turn);
					if (winner = true) {
						keepGoing = false;
						break;
					}
				}

				turn++;
			}
			else if (numPlayers == 4) {
				for (int i = 0; i < 4; i++) {
					winner = loop(players4[i], turn);
					if (winner = true) {
						keepGoing = false;
						break;
					}
				}

				turn++;
			}
			else if (numPlayers == 5) {
				for (int i = 0; i < 5; i++) {
					winner = loop(players5[i], turn);
					if (winner = true) {
						keepGoing = false;
						break;
					}
				}

				turn++;
			}
			else if (numPlayers == 6) {
				for (int i = 0; i < 6; i++) {
					winner = loop(players6[i], turn);
					if (winner = true) {
						keepGoing = false;
						break;
					}
				}

				turn++;
			}

		
		}
	
	
	
	}

	player GameEngine::getPlayer2(int index) {
		return players2[index];
	
	}
	player GameEngine::getPlayer3(int index) {
		return players3[index];

	}
	player GameEngine::getPlayer4(int index) {
		return players4[index];

	}
	player GameEngine::getPlayer5(int index) {
		return players5[index];

	}
	player GameEngine::getPlayer6(int index) {
		return players6[index];

	}
	
	string GameEngine::getBorough(int position) {
	Borough* b=	m->getBorough(position);
	string name = b->getBName();
	
	}