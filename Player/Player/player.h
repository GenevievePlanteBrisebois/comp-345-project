#pragma once
#include <iostream>
#include <cstdlib>
#include "player.h"
//includes of .h that are in different solutions
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Cards_Deck.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Active_Monsters.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\Tokens.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Dice\Dice.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Map Implementation\Map.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Map Implementation\Borough.h"
#include "C:\Users\Genevieve\Documents\SCHOOL\University\fall 2018\comp 345\comp345-kingsOfNY\Cards\BU.h"
class player {
public:
	player();
	~player();
	void setMonster(Monsters* a);
	void setTokens(Tokens* t, int i);
	void setTokens(Tokens* a);
	void setCard(Cards* a);
	Cards* getCard(Cards* a);
	Monsters* getMonster();
	Tokens* getToken(int i);
	Monsters* getPlayer(string name, Active_Monsters * a[]);

	void addToken(Tokens* token);
	void removeToken(Tokens* token);

	void rollDice();
	void resolveDice(Map m, Active_Monsters * a[], BU* b);

	void useCard(Cards* a);
	void buyCard( Cards* a);

	void move(string borough, Map m);	
	
	int getPosition();
	void setPosition(int i);

	void removeDestructionPoints(int i);
	int getDestructionPoints();
};