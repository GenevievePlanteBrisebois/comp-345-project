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

class TokensDeck{
public:
	TokensDeck();
	~TokensDeck();

};