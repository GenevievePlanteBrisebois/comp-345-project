//written by Genevieve Plante-Brisebois 40003112 fall 2018 comp 345

#pragma once
#include <iostream>

using namespace std;

class Tokens {
public:
	Tokens();
	Tokens(string type);
	~Tokens();

	Tokens* create_carapace();
	Tokens* create_souvenir();
	Tokens* create_jinx();
	Tokens* create_web();
};

