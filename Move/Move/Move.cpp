/*
created by Genevieve Plante-Brisebois
40003112
comp 345 fall 2018
*/

#include<iostream>
#include "../comp345-kingsOfNY/Player/Player/player.h"
#include "Move.h"
#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"

Move::Move() {


}

Move::~Move() {

}

void Move::move(player* player, Map* m) {
	//verification that manhattan is empty
	if (m->getBorough(8)->getStatus() == false && m->getBorough(9)->getStatus() == false && m->getBorough(10)->getStatus() == false) {
		cout << "Manhattan is empty and as such you are moving to Lower Manhattan" << endl;
		player->move(m->getBorough(8)->getName(), m);
	}
	//case player is in manhattan and has been attacked
	else if (player->getPosition() == 8 && player->getMonster()->getCountAttack()!=0) {
		player->getMonster()->setCountAttack(0);
		cout << "You have been attacked. Do you wish to move to Mid Town or to move to another borough?" << endl;
		cout << "1-Mid Town 2-Other" << endl;
		int ans;
		cin >> ans;
		if (ans=1)
		player->move(m->getBorough(9)->getName(), m);
		else {
			cout << "Your options to move are: \n1- Staten Island \n 2- Bronx \n3-Queens \n4-Brooklyn \n5- Stay" << endl;
			int answer;
			cin >> answer;

			if (answer == 1) {
				player->move("Staten Island", m);
			}
			else if (answer == 2) {
				player->move("Bronx", m);
			}
			else if (answer == 3) {
				player->move("Queens", m);
			}
			else if (answer == 4) {
				player->move("Brooklyn", m);
			}
		}
	}
	else if (player->getPosition() == 9 && player->getMonster()->getCountAttack() != 0) {
		player->getMonster()->setCountAttack(0);
		cout << "You have been attacked. Do you wish to move to Upper Manhattan or to move to another borough?" << endl;
		cout << "1-Mid Town 2-Other" << endl;
		int ans;
		cin >> ans;
		if (ans = 1)
		player->move(m->getBorough(10)->getName(), m);
	}
	//case the player is in lower manhattan and needs to move to midtown
	else if (player->getPosition() == 8) {

		cout << "You are moving to Mid Manhattan" << endl;
		player->move(m->getBorough(9)->getName(), m);
	}
	else if (player->getPosition() == 9) {
		cout << "You are moving to Upper Manhattan" << endl;
		player->move(m->getBorough(10)->getName(), m);
	}
	//case player is already in upper manhattan and gannot go further unless attacked
	else if (player->getPosition() == 10) {
		cout << "You do not need to move as you are in Upper Manhattan" << endl;
	}
	//case there is someone in manhattan
	else if (m->getBorough(8)->getStatus() == true || m->getBorough(9)->getStatus() == true || m->getBorough(10)->getStatus() == true) {
		player->getMonster()->setCountAttack(0);
		cout << "There is already a monster in Manhattan. Please choose another borough to move to or stay in your current borough. write the number corresponding to your choice" << endl;
		cout << "1- Staten Island \n 2- Bronx \n3-Queens \n4-Brooklyn \n5- Stay" << endl;
		int answer;
		cin >> answer;

		if (answer == 1) {
			player->move("Staten Island", m);
		}
		else if (answer == 2) {
			player->move("Bronx", m);
		}
		else if (answer == 3) {
			player->move("Queens", m);
		}
		else if (answer == 4) {
			player->move("Brooklyn", m);
		}
		else if (answer == 5) {
			cout << "You have chosen to remain at the same place" << endl;
		}
		
	}
}