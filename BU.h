//written by Genevieve Plante-Brisebois 40003112 comp 345 fall 2018

#pragma once
#include <iostream>
#include <cstdlib>
#include "Buildings.h"
#include "Units.h"

using namespace std;

class BU: public Units, public Buildings {
	BU();
	~BU();

	Units* destroy_building(int damage, Buildings* building);
	void destroy_unit(Units* a);
	void build_building_deck();
	void shuffle();

};