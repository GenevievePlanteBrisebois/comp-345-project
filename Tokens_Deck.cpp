//class made by Genevieve Plante-Brisebois 40003112 for COMP 345 fall2018

#include <iostream>
#include "Tokens.h"
#include"Tokens_Deck.h"
using namespace std;





	Tokens* souvenir[5];
	Tokens* carapace[15];
	Tokens* web[13];
	Tokens* jinx[13];







Tokens_Deck::Tokens_Deck()
{
	for (int i = 0; i < 5; i++) {
		souvenir[i] = create_souvenir();
	}
	for (int i = 0; i < 15; i++) {
		carapace[i] = create_carapace();
	}
	for (int i = 0; i < 13; i++) {
		web[i] = create_web();
	}
	for (int i = 0; i < 13; i++) {
		jinx[i] = create_jinx();
	}

}

Tokens_Deck::~Tokens_Deck()
{
	delete[] * web;
	delete[] * jinx;
	delete[] * souvenir;
	delete[] * carapace;

}
