/*
written by Geneveieve Plante-Brisebois
40003112

COMP 345 fall 2018
*/

#include "GameEngine.h"
#include "StatsObserver.h"
GameEngine s;

int stats_numPlayers;
player* stats_p1;
player* stats_p2;
player* stats_p3;
player* stats_p4;
player* stats_p5;
player* stats_p6;





StatsObserver::StatsObserver(){

}

StatsObserver::~StatsObserver() {

}


void StatsObserver::displayStats() {
	stats_numPlayers = s.GetNumPlayers();
	
	//get the stats for the number of players
	if (stats_numPlayers == 2) {
		stats_p1 = s.getPlayer2(0);
		stats_p2 = s.getPlayer2(1);
		string location1;
		string location2;

		//get the borough they are in

		location1 = s.getBorough(stats_p1->getPosition());
		location2 = s.getBorough(stats_p2->getPosition());


		cout << "Player 1 :" << stats_p1->getMonster()->getName() << " has " << stats_p1->getMonster()->getHealth() << " health and " << stats_p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << stats_p2->getMonster()->getName() << " has " << stats_p2->getMonster()->getHealth() << " health and " << stats_p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;

	}
	else if (stats_numPlayers == 3) {
		stats_p1 = s.getPlayer3(0);
		stats_p2 = s.getPlayer3(1);
		stats_p3 = s.getPlayer3(2);
		string location1;
		string location2;
		string location3;

		//get the borough they are in

		location1 = s.getBorough(stats_p1->getPosition());
		location2 = s.getBorough(stats_p2->getPosition());
		location3 = s.getBorough(stats_p3->getPosition());


		cout << "Player 1 :" << stats_p1->getMonster()->getName() << " has " << stats_p1->getMonster()->getHealth() << " health  and " << stats_p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << stats_p2->getMonster()->getName() << " has " << stats_p2->getMonster()->getHealth() << " health  and " << stats_p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << stats_p3->getMonster()->getName() << " has " << stats_p3->getMonster()->getHealth() << " health  and " << stats_p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;

	}
	else if (stats_numPlayers == 4) {
		stats_p1 = s.getPlayer4(0);
		stats_p2 = s.getPlayer4(1);
		stats_p3 = s.getPlayer4(2);
		stats_p4 = s.getPlayer4(3);
		string location1;
		string location2;
		string location3;
		string location4;

		//get the borough they are in

		location1 = s.getBorough(stats_p1->getPosition());
		location2 = s.getBorough(stats_p2->getPosition());
		location3 = s.getBorough(stats_p3->getPosition());
		location4 = s.getBorough(stats_p4->getPosition());


		cout << "Player 1 :" << stats_p1->getMonster()->getName() << " has " << stats_p1->getMonster()->getHealth() << " health  and " << stats_p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << stats_p2->getMonster()->getName() << " has " << stats_p2->getMonster()->getHealth() << " health  and " << stats_p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << stats_p3->getMonster()->getName() << " has " << stats_p3->getMonster()->getHealth() << " health  and " << stats_p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << stats_p4->getMonster()->getName() << " has " << stats_p4->getMonster()->getHealth() << " health  and " << stats_p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;

	}
	else if (stats_numPlayers == 5) {
		stats_p1 = s.getPlayer5(0);
		stats_p2 = s.getPlayer5(1);
		stats_p3 = s.getPlayer5(2);
		stats_p4 = s.getPlayer5(3);
		stats_p5 = s.getPlayer5(4);
		string location1;
		string location2;
		string location3;
		string location4;
		string location5;

		//get the borough they are in

		location1 = s.getBorough(stats_p1->getPosition());
		location2 = s.getBorough(stats_p2->getPosition());
		location3 = s.getBorough(stats_p3->getPosition());
		location4 = s.getBorough(stats_p4->getPosition());
		location5 = s.getBorough(stats_p5->getPosition());


		cout << "Player 1 :" << stats_p1->getMonster()->getName() << " has " << stats_p1->getMonster()->getHealth() << " health  and " << stats_p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << stats_p2->getMonster()->getName() << " has " << stats_p2->getMonster()->getHealth() << " health  and " << stats_p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << stats_p3->getMonster()->getName() << " has " << stats_p3->getMonster()->getHealth() << " health  and " << stats_p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << stats_p4->getMonster()->getName() << " has " << stats_p4->getMonster()->getHealth() << " health  and " << stats_p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;
		cout << "Player 5 :" << stats_p5->getMonster()->getName() << " has " << stats_p5->getMonster()->getHealth() << " health  and " << stats_p5->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location5 << endl;

	}
	else if (stats_numPlayers == 6) {
		stats_p1 = s.getPlayer6(0);
		stats_p2 = s.getPlayer6(1);
		stats_p3 = s.getPlayer6(2);
		stats_p4 = s.getPlayer6(3);
		stats_p5 = s.getPlayer6(4);
		stats_p6 = s.getPlayer6(5);
		string location1;
		string location2;
		string location3;
		string location4;
		string location5;
		string location6;

		//get the borough they are in

		location1 = s.getBorough(stats_p1->getPosition());
		location2 = s.getBorough(stats_p2->getPosition());
		location3 = s.getBorough(stats_p3->getPosition());
		location4 = s.getBorough(stats_p4->getPosition());
		location5 = s.getBorough(stats_p5->getPosition());
		location6 = s.getBorough(stats_p6->getPosition());

		cout << "Player 1 :" << stats_p1->getMonster()->getName() << " has " << stats_p1->getMonster()->getHealth() << " health  and " << stats_p1->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location1 << endl;
		cout << "Player 2 :" << stats_p2->getMonster()->getName() << " has " << stats_p2->getMonster()->getHealth() << " health  and " << stats_p2->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location2 << endl;
		cout << "Player 3 :" << stats_p3->getMonster()->getName() << " has " << stats_p3->getMonster()->getHealth() << " health  and " << stats_p3->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location3 << endl;
		cout << "Player 4 :" << stats_p4->getMonster()->getName() << " has " << stats_p4->getMonster()->getHealth() << " health  and " << stats_p4->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location4 << endl;
		cout << "Player 5 :" << stats_p5->getMonster()->getName() << " has " << stats_p5->getMonster()->getHealth() << " health  and " << stats_p5->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location5 << endl;
		cout << "Player 6 :" << stats_p6->getMonster()->getName() << " has " << stats_p6->getMonster()->getHealth() << " health  and " << stats_p6->getMonster()->getVictoryPoint() << "VictoryPoints. Located in " << location6 << endl;

	
	}

}