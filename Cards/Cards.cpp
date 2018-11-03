//this class is made by Genevieve Plante-Brisebois 40003112 for COMP 345 in fall 2018

#include <iostream>
#include <cstdlib>
#include <string>
#include "Cards.h"

using namespace std;



	int energy_cost;
	string card_type;
	string card_effect;
	string card_name;
	bool status;
	


	//destructor
	Cards::~Cards() {

	}

	//getters and setters
	bool Cards::getStatus() {
		return status;
	}
	string Cards::getName() {
		return card_name;
	}

	string Cards::getEffect() {
		return card_effect;
	}

	string Cards::getCardType() {
		return card_type;
	}
	int Cards::getCost() {
		return energy_cost;
	}

	void Cards::setName(string na) {
		card_name = na;
	}

	void Cards::setEffect(string ef) {
		card_effect = ef;
	}

	void Cards::setCost(int cost) {
		energy_cost = cost;
	}

	void Cards::setCardType(string cardType) {
		card_type = cardType;
	}
	void Cards::setStatus(bool stat) {
		status = stat;
	}

	string Cards::toString() {
		//string name = card->getName();
		//string cost = to_string(card->getCost());
		//string effect = card->effect;
		//string type = card->getCardType();
		std::string description;
			if (status == true) {
				description = "Card name: " + card_name + "\nEnergy Cost: " + to_string(energy_cost) + "\nCard Type: " + card_type + "\nEffect: " + card_effect + "\nStatus: True";
			}
			else {

				description = "Card name: " + card_name + "\nEnergy Cost: " + to_string(energy_cost) + "\nCard Type: " + card_type + "\nEffect: " + card_effect + "\nStatus: False";
			}//cout << description;
		return description;

	}


Cards::Cards() {

}
Cards::Cards(std::string name, int cost, string card_ty, string effect, bool status)
{
	card_name = name;
	card_type = card_ty;
	card_effect = effect;
	energy_cost = cost;
	status = false;

}


