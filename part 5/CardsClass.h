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


};

class Cards_Deck {
public:
	Cards_Deck();
	~Cards_Deck();
	void build_special_deck();
	void build_regular_deck();
	void suffle();
	string toString(Cards* card);

};
