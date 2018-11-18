/*
written by Genevieve Plante-Brisebois
40003112
COMP 345 Fall 2018
*/



#include <iostream>
#include"Player/Player/player.h"

using namespace std;

#pragma once

class BuyCards : public Cards_Deck{

bool changePossibleBuy(player* player);
void buyCards( player* player);
void showPossibleBuy();

BuyCards();
~BuyCards();




};