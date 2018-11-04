//written by Genevieve Plante-Brisebois 40003112 comp 345 fall 2018

#pragma once
#include <iostream>
#include <cstdlib>
#include "Buildings.h"
#include "Units.h"

using namespace std;

class BU: public Units, public Buildings {
public:
	BU();
	~BU();

	void destroy_building(int damage, Buildings* building, string burrough);
	void destroy_unit(Units* a, string burrough);
	void destroy_unit(int i);
	void build_building_deck();
	void shuffle();
	Buildings* get_building_from_set(int i, string burrough);
	Units* get_unit_from_set(int i, string burrough);

};