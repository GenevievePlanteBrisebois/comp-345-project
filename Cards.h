//Written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

#pragma once
#include <iostream>

using namespace std;

class Cards
{
public:
	Cards();
	Cards(string name, int cost, string card_type, string effect);
	~Cards();
	string getName();
	string getEffect();
	string getCardType();
	int getCost();
	void setName(string name);
	void setEffect(string effect);
	void setCost(int cost);
	void setCardType(string cardType);
	string toString();


};
