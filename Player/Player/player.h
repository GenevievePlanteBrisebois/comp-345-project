#pragma once
#include <iostream>
#include "player.h"
//includes of .h that are in different solutions
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Tokens.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Dice\Dice.h"


class player {
	player();
	~player();
	void setMonster(Monsters* a);
	void setTokens(Tokens* t, int i);
	void setTokens(Tokens* a);
	Monsters* getMonster();
	Tokens* getToken(int i);
	void addToken(Tokens* token);
	void removeToken(Tokens* token);

};