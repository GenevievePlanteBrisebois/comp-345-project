//Written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

#pragma once
#include <iostream>

using namespace std;

class Cards
{
public:
	Cards();
	//if the status is false the card is not being used by a player if the status is true the card is being used by a player
	Cards(string name, int cost, string card_type, string effect, bool status);
	~Cards();
	string getName();
	string getEffect();
	string getCardType();
	int getCost();
	bool getStatus();
	void setName(string name);
	void setEffect(string effect);
	void setCost(int cost);
	void setCardType(string cardType);
	void setStatus(bool stat);
	string toString();


};
