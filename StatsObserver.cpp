/*
written by Geneveieve Plante-Brisebois
40003112

COMP 345 fall 2018
*/

#include "GameEngine.h"
#include "StatsObserver.h"
GameEngine s;

int numPlayers;
player * p1;
player* p2;
player* p3;
player* p4;
player* p5;
player* p6;





StatsObserver::StatsObserver(){

}

StatsObserver::~StatsObserver() {

}


void StatsObserver::displayStats() {
	numPlayers = s.GetNumPlayers();
	
	//get the stats for the number of players
	if (numPlayers == 2) {
		p1 = s.getPlayer2(0);
		p2 = s.getPlayer2(1);
		string location1;
		string location2;

		//get the borough they are in

		location1 = s.getBorough(p1->getPosition());
		location2 = s.getBorough(p2->getPosition());


		cout << "Player 1 :" << p1->getMonster()->getName() << " has " << p1->getMonster()->getHealth() << " and " << p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << p2->getMonster()->getName() << " has " << p2->getMonster()->getHealth() << " and " << p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;

	}
	else if (numPlayers == 3) {
		p1 = s.getPlayer3(0);
		p2 = s.getPlayer3(1);
		p3 = s.getPlayer3(2);
		string location1;
		string location2;
		string location3;

		//get the borough they are in

		location1 = s.getBorough(p1->getPosition());
		location2 = s.getBorough(p2->getPosition());
		location3 = s.getBorough(p3->getPosition());


		cout << "Player 1 :" << p1->getMonster()->getName() << " has " << p1->getMonster()->getHealth() << " and " << p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << p2->getMonster()->getName() << " has " << p2->getMonster()->getHealth() << " and " << p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << p3->getMonster()->getName() << " has " << p3->getMonster()->getHealth() << " and " << p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;

	}
	else if (numPlayers == 4) {
		p1 = s.getPlayer4(0);
		p2 = s.getPlayer4(1);
		p3 = s.getPlayer4(2);
		p4 = s.getPlayer4(3);
		string location1;
		string location2;
		string location3;
		string location4;

		//get the borough they are in

		location1 = s.getBorough(p1->getPosition());
		location2 = s.getBorough(p2->getPosition());
		location3 = s.getBorough(p3->getPosition());
		location4 = s.getBorough(p4->getPosition());


		cout << "Player 1 :" << p1->getMonster()->getName() << " has " << p1->getMonster()->getHealth() << " and " << p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << p2->getMonster()->getName() << " has " << p2->getMonster()->getHealth() << " and " << p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << p3->getMonster()->getName() << " has " << p3->getMonster()->getHealth() << " and " << p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << p4->getMonster()->getName() << " has " << p4->getMonster()->getHealth() << " and " << p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;

	}
	else if (numPlayers == 5) {
		p1 = s.getPlayer5(0);
		p2 = s.getPlayer5(1);
		p3 = s.getPlayer5(2);
		p4 = s.getPlayer5(3);
		p5 = s.getPlayer5(4);
		string location1;
		string location2;
		string location3;
		string location4;
		string location5;

		//get the borough they are in

		location1 = s.getBorough(p1->getPosition());
		location2 = s.getBorough(p2->getPosition());
		location3 = s.getBorough(p3->getPosition());
		location4 = s.getBorough(p4->getPosition());
		location5 = s.getBorough(p5->getPosition());


		cout << "Player 1 :" << p1->getMonster()->getName() << " has " << p1->getMonster()->getHealth() << " and " << p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << p2->getMonster()->getName() << " has " << p2->getMonster()->getHealth() << " and " << p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << p3->getMonster()->getName() << " has " << p3->getMonster()->getHealth() << " and " << p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << p4->getMonster()->getName() << " has " << p4->getMonster()->getHealth() << " and " << p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;
		cout << "Player 5 :" << p5->getMonster()->getName() << " has " << p5->getMonster()->getHealth() << " and " << p5->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location5 << endl;

	}
	else if (numPlayers == 6) {
		p1 = s.getPlayer6(0);
		p2 = s.getPlayer6(1);
		p3 = s.getPlayer6(2);
		p4 = s.getPlayer6(3);
		p5 = s.getPlayer6(4);
		p6 = s.getPlayer6(5);
		string location1;
		string location2;
		string location3;
		string location4;
		string location5;
		string location6;

		//get the borough they are in

		location1 = s.getBorough(p1->getPosition());
		location2 = s.getBorough(p2->getPosition());
		location3 = s.getBorough(p3->getPosition());
		location4 = s.getBorough(p4->getPosition());
		location5 = s.getBorough(p5->getPosition());
		location6 = s.getBorough(p6->getPosition());

		cout << "Player 1 :" << p1->getMonster()->getName() << " has " << p1->getMonster()->getHealth() << " and " << p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << p2->getMonster()->getName() << " has " << p2->getMonster()->getHealth() << " and " << p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << p3->getMonster()->getName() << " has " << p3->getMonster()->getHealth() << " and " << p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << p4->getMonster()->getName() << " has " << p4->getMonster()->getHealth() << " and " << p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;
		cout << "Player 5 :" << p5->getMonster()->getName() << " has " << p5->getMonster()->getHealth() << " and " << p5->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location5 << endl;
		cout << "Player 6 :" << p6->getMonster()->getName() << " has " << p6->getMonster()->getHealth() << " and " << p6->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location6 << endl;

	
	}

}