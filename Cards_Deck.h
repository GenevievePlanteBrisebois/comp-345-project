//Written by Genevieve Plante-Brisebois 40003112 for COMP 345 fall 2018

#pragma once
#include <iostream>
#include "Cards.h"
using namespace std;


class Cards_Deck :public Cards {
public:
	Cards_Deck();
	~Cards_Deck();
	Cards* getRegularCard(int i);
	Cards* getSpecialCards(int i);
	void shuffle(Cards* regular_deck[]);


};
