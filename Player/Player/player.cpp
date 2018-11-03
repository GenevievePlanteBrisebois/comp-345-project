//since the headers of the other parts are in other folders we need to put the path that leads to the header. The path will need to be adapted according to the machine it runs on
//file created by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

//not including all of the cards classes in order to not import methods that are not relevant to the player class
#include <iostream>
#include "player.h"
//includes of .h that are in different solutions
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Tokens.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Dice\Dice.h"

//starting to write the player methods
Monsters* player_monster;
Tokens* player_tokens[20];


//constructors and destructors
player::player() {
	player_monster = new Monsters();
	

}

player::~player(){
	delete player_monster;
	delete [] player_tokens;
}

//setters and getters
void player::setMonster(Monsters* a) {
	player_monster = a;

}

void player::setTokens(Tokens* t, int i) {
	player_tokens[i] = t;
}

void player::setTokens(Tokens* a) {
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] == nullptr) {
			player_tokens[i] = a;
		}
	}
}

Monsters* player::getMonster() {
	return player_monster;
}

Tokens* player::getToken(int i) {
	return player_tokens[i];
}


//to make the monster for the player will be in the driver or in the driver of the game.
//all necessary methods to create/add a monster are in the monster and active_monsters classes

//dice rolling methods

//map methods

//tokens methods
//methods to add and remove tokens from the player

void player::addToken(Tokens* token) {
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] == nullptr) {
			player_tokens[i] = token;
		}
	}
}

void player::removeToken(Tokens* token) {
	string type = token->getType();
	for (int i = 0; i < 20; i++) {
		if (player_tokens[i] != nullptr && player_tokens[i]->getType() == token->getType()) {
			player_tokens[i] = nullptr;
			break;//end the loop so that we do not go through the whole loop
		}	
	}

}
