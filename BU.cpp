//file created by Genevieve Plante-Brisebois 40003112 for comp 345 fall 2018

#include <iostream>
#include <cstdlib>
#include "Buildings.h"
#include "Units.h"
#include "BU.h"

using namespace std;


//class that brings together the units and the buildings

	Buildings* start_set[45];
	Units* unit_set[45];

	//method to damage the building. when a building is destroyed it produces a unit
	//the effect of destroying the building will have to be done in another class to call on the heal, add vp methods of monsters
	void BU::destroy_building(int damage, Buildings* building, int index) {

		int dur = building->getDurability();
		int bu = dur - damage;
		Units* new_unit;

		if (building->getDurability() == 1) {
			new_unit = create_infantry();
			delete building;
			
		}
		else if (building->getDurability() == 2) {
			new_unit = create_jet();
			
			delete building;
		}
		else {
			new_unit = create_tank();
			
			delete building;
		}
		unit_set[index] = new_unit;

	}
	//the reward will have to be given according to the unit type in the driver
	//method to damage the units when a unit dies it is taken off the board
	void BU::destroy_unit(Units* a) {
		delete a;
	}

	void BU::destroy_unit(int i) {
		delete unit_set[i];
	}


	//suffle method for to mix the buildings before we put them on the board
	void BU::shuffle() {
		Buildings* temp[45];
		bool shuffle = true;
		bool innerLoop = true;
		int k = 0;
		int i;
		bool occupied, complete;
		//make a temporary array that will store the suffled values
		while (shuffle = true) {
			i = rand() % 44;
			for (int j = 0; j < 45; j++) {
				if (temp[j] != nullptr) {
					occupied = true;
				}
				else
					occupied = false;
			}
			if (occupied == false) {
				temp[i] = start_set[k];
				k = k + 1;
			}

			//verify if the whole temp array has been filled

			for (int j = 0; j < 45; j++) {
				if (temp[j] == nullptr)
					complete = false;
			}
			if (complete != false) {
				complete = true;
				shuffle = false;
			}

		}
		//replace the order of the cards in the regular deck by the cards in the temp 
		for (int j = 0; j < 45; j++) {
			start_set[j] = temp[j];
		}

		delete[] * temp;
		

	}
	//method to build the deck of the buildings
	void BU::build_building_deck() {
		for (int i = 0; i < 45; i++) {
			if (i < 5) {
				Buildings * building = create_hospital_1();
				start_set[i] = building;
			}
			else if (i < 10 && i>4) {
				Buildings * building = create_hospital_2();
				start_set[i] = building;
			}
			else if (i > 9 && i < 15) {
				Buildings * building = create_hospital_3();
				start_set[i] = building;
			}
			else if (i > 14 && i < 20) {
				Buildings * building = create_high_rise_1();
				start_set[i] = building;
			}
			else if (i > 19 && i < 25) {
				Buildings * building = create_high_rise_2();
				start_set[i] = building;
			}
			else if (i > 24 && i < 30) {
				Buildings * building = create_high_rise_3();
				start_set[i] = building;
			}
			else if (i > 29 && i < 35) {
				Buildings * building = create_power_plant_1();
				start_set[i] = building;
			}
			else if (i > 34 && i < 40) {
				Buildings * building = create_power_plant_2();
				start_set[i] = building;
			}
			else {
				Buildings * building = create_power_plant_3();
				start_set[i] = building;
			}

		}
	}


BU::BU()
{
	
}

BU ::~BU()
{
	delete[] * start_set;
	delete[] * unit_set;
}

Buildings* BU::get_building_from_set(int i) {
	return start_set[i];
}
Units* BU:: get_unit_from_set(int i) {
	return unit_set[i];
}