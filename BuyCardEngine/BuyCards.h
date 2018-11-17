/*
written by Genevieve Plante-Brisebois
40003112
COMP 345 Fall 2018
*/



#include <iostream>
#include"Player/Player/player.h"


#pragma once

class BuyCards : public Cards_Deck{

void changePossibleBuy(player* player);
void buyCards(string cardName, player* player);
void showPossibleBuy();

BuyCards();
~BuyCards();




};