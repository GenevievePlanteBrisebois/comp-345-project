#pragma once
#include <iostream>
#include <cstdlib>
#include "player.h"
//includes of .h that are in different solutions

#include "../comp345-kingsOfNY/Cards/Cards_Deck.h"
#include "../comp345-kingsOfNY/Cards/BU.h"
#include "../comp345-kingsOfNY/Cards/Active_Monsters.h"
#include "../comp345-kingsOfNY/Cards/Tokens.h"
#include "../comp345-kingsOfNY/Dice/Dice.h"
#include "../comp345-kingsOfNY/Map Implementation/Map.h"
#include "../comp345-kingsOfNY/Map Implementation/Borough.h"

using namespace std;

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
	Monsters* getPlayer(string name, Active_Monsters * a);

	void addToken(Tokens* token);
	void removeToken(Tokens* token);

	void rollDice();
	void resolveDice(Map* m, Monsters * a[], BU* b, Cards_Deck* cards, player* player[]);

	void resolveHeal(int heal);
	void resolveOuch(int ouch, Map* m, player* player[], Cards_Deck* cards, BU* b);
	void resolveAttack(int attack, Map* m, Monsters * a[]);
	void resolveEnergy(int energy);
	void resolveCelebrity(int celeb, Cards_Deck*  cards, player* players[]);
	void resolveDestruction(int destruction, BU* bu, Map* m);


	void useCard(Cards* a);
	void buyCard( Cards* a);

	bool move1(string borough, Map* m);	
	void move(string borough, Map* m);
	int getPosition();
	void setPosition(int i);

	void removeDestructionPoints(int i);
	int getDestructionPoints();
};