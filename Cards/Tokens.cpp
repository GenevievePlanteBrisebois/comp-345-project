//class made by Genevieve Plante-Brisebois 40003112 for COMP 345 fall2018

#include <iostream>
#include "Tokens.h"
using namespace std;

/*
Tokens are of four different type and there are 46 in total.
They are of type Carapace (15), Souvenir(5), Web(13) and Jinx(13)

Their effects on the game are related to the cards that allows to use them.
web:"When you deal damage to Monsters,
	 give them a Web token. A Monster has one fewer reroll on his turn for each Web token he has.
	 A Monster can choose to use an ATTACK to discard a Web token instead of using it to attack."

jinx: "When you deal damage to Monsters, give each a Curse token. Each time a Monster wants to reroll
	  OUCH, he must spend 1 ENERGY_POINT for each Curse token he has.\nA Monster may use a HEART to
	  discard a Curse token instead of using it to heal."

carapace:  "Your HEART_POINT maximum is increased by 2 as long as you have this card. For each OUCH
			you roll, place a Carapace token on this card.You can discard this card to heal 1 damage
			for each Carapace token on it."

souvenir:"Place a Souvenir token in your current borough, and in each borough you enter that does not
		 already have a Souvenir token. Gain 1 VICTORY_POINT and 1 ENERGY_POINT each time you place a
		 Souvenir token."


*/

	string types_token[4] = { "carapace", "souvenir", "jinx", "web" };
	string token_type;
	Tokens* tokens;
	string Tokens::getType() {

		return token_type;
	}
	Tokens* Tokens::create_carapace() {
		Tokens* carapace = new Tokens(types_token[0]);
		return carapace;
	}

	Tokens* Tokens::create_souvenir() {
		Tokens* souvenir = new Tokens(types_token[1]);
		return souvenir;
	}

	Tokens* Tokens::create_jinx() {
		Tokens* jinx = new Tokens(types_token[2]);
		return jinx;
	}

	Tokens* Tokens::create_web() {
		Tokens* web = new Tokens(types_token[3]);
		return web;
	}





Tokens::Tokens()
{
	
}

Tokens::Tokens(string type)
{
	token_type = type;
}

Tokens::~Tokens()
{
	delete tokens;
}
