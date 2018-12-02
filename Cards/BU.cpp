//file created by Genevieve Plante-Brisebois 40003112 for comp 345 fall 2018

#include <iostream>
#include <cstdlib>
#include "Buildings.h"
#include "Units.h"
#include "BU.h"

using namespace std;


//class that brings together the units and the buildings

	
Buildings* start_set[45];
Buildings* lower_manhattan_buildings[7];
Buildings* midtown_buildings[7];
Buildings* upper_buildings[7];
Buildings* queens_buildings[6];
Buildings* staten_buildings[6];
Buildings* bronx_buildings[6];
Buildings* brooklyn_buildings[6];

Units* lower_manhattan_units[7];
Units* midtown_units[7];
Units* upper_units[7];
Units* queens_units[6];
Units* staten_units[6];
Units* bronx_units[6];
Units* brooklyn_units[6];

	//method to damage the building. when a building is destroyed it produces a unit
	//the effect of destroying the building will have to be done in another class to call on the heal, add vp methods of monsters
	void BU::destroy_building(int damage, Buildings* building, string burrough) {
		int dur = building->getDurability();
		int bu = dur - damage;
		Units* new_unit;
		//destroying the building
		if (building->getDurability() == 1) {
			new_unit = create_infantry();
			building =nullptr;

		}
		else if (building->getDurability() == 2) {
			new_unit = create_jet();

			building = nullptr;
		}
		else {
			new_unit = create_tank();

			building = nullptr;
		}
		//adding the new unit to the right array of units
		if (burrough == "Staten Island") {
			for (int i = 0; i < 6; i++) {
				if (staten_units[i] == nullptr)
					staten_units[i] = new_unit;
			}
		}
		else if (burrough == "Lower Manhattan") {
			for (int i = 0; i < 7; i++) {
				if (lower_manhattan_units[i] == nullptr)
					lower_manhattan_units[i] = new_unit;
			}
		}
		else if (burrough == "Bronx") {
			for (int i = 0; i < 6; i++) {
				if (bronx_units[i] == nullptr)
					bronx_units[i] = new_unit;
			}
		}
		else if (burrough == "Queens") {
			for (int i = 0; i < 6; i++) {
				if (queens_units[i] == nullptr)
					queens_units[i] = new_unit;
			}
		}
		else if (burrough =="Brooklyn" ) {
			for (int i = 0; i < 6; i++) {
				if (brooklyn_units[i] == nullptr)
					brooklyn_units[i] = new_unit;
			}
		}
		else if (burrough == "Mid Manhattan") {
			for (int i = 0; i < 7; i++) {
				if (midtown_units[i] == nullptr)
					midtown_units[i] = new_unit;
			}
		}
		else if (burrough == "Upper Manhattan") {
			for (int i = 0; i < 7; i++) {
				if (upper_units[i] == nullptr)
					upper_units[i] = new_unit;
			}
		}
		
		

	}
	//the reward will have to be given according to the unit type in the driver
	//method to damage the units when a unit dies it is taken off the board
	void BU::destroy_unit(Units* a, string burrough) {
		string type = a->getType();
		
		
		if (burrough == "Staten Island") {
			 

			 for (int i = 0; i < 6; i++) {
				 if (staten_units[i]->getType() == type)
					 staten_units[i]= nullptr;
			 }
		}
		else if (burrough == "Lower Manhattan") {
			for (int i = 0; i < 7; i++) {
				if (lower_manhattan_units[i]->getType() == type)
					lower_manhattan_units[i] = nullptr;
			}
		}
		else if (burrough == "Bronx") {
			 
			 for (int i = 0; i < 6; i++) {
				 if (bronx_units[i]->getType() == type)
					 bronx_units[i] = nullptr;
			 }

		}
		else if (burrough == "Queens") {
			
			 for (int i = 0; i < 6; i++) {
				 if (queens_units[i]->getType() == type)
					 queens_units[i]= nullptr;
			 }
		}
		else if (burrough == "Brooklyn") {
			 
			 for (int i = 0; i < 6; i++) {
				 if (brooklyn_units[i]->getType() == type)
					 brooklyn_units[i] = nullptr;
			 }

		}
		else if (burrough == "Mid Manhattan") {
			for (int i = 0; i < 7; i++) {
				if (midtown_units[i]->getType() == type)
					midtown_units[i] = nullptr;
			}
			 
		}
		else if (burrough == "Upper Manhattan") {

			for (int i = 0; i < 7; i++) {
				if (upper_units[i]->getType() == type)
					upper_units[i]= nullptr;
			}
			 
		}
	}

	


	//suffle method for to mix the buildings before we put them on the board
	void BU::shuffle() {
		Buildings* temp[45] ;
		bool shuffle = true;
		bool innerLoop = true;
		int k = 0;
		int i;
		bool occupied=false;
		bool complete=true;
		//putting all temp to null
		for (int i = 0; i < 45; i++){
			temp[i] = NULL;
		}
		//make a temporary array that will store the suffled values
		while (shuffle == true) {
			
			while (k < 45) {
				i = rand() % 45;
				if (temp[i] != NULL) {
					occupied = true;
				}
				else
					occupied = false;
				if (occupied == false) {
					temp[i] = start_set[k];
					k = k + 1;
				}

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
			//resetting complete to true so that if it goes back to verification it has a chance of being true;
			complete = true;

		}
		//replace the order of the cards in the regular deck by the cards in the temp 
		for (int j = 0; j < 45; j++) {
			start_set[j] = temp[j];
		}

		
		
		//loops each of the length of each array. it will divie up the shuffled array of buildings per area. 
		//guarentees that each game will have a different repartition of their content.the burrough of manhattan have 7
		
		
		
		for (int i = 0; i < 7; i++) {

			lower_manhattan_buildings[i] = start_set[i];
		}
		for (int i = 0; i < 7; i++) {
			int j = 7;
			midtown_buildings[i] = start_set[j];
			j++;
		}
		for (int i = 0; i < 7; i++) {
			int j = 14;
			upper_buildings[i] = start_set[j];
			j++;
		}
		for (int i = 0; i < 6; i++) {
			int j = 21;
			queens_buildings[i] = start_set[j];
			j++;
		}
		for (int i = 0; i < 6; i++) {
			int j = 27;
			staten_buildings[i] = start_set[j];
			j++;
		}
		for (int i = 0; i < 6; i++) {
			int j = 33;
			bronx_buildings[i] = start_set[j];
			j++;
		}
		for (int i = 0; i < 6; i++) {
			int j = 39;
			brooklyn_buildings[i] = start_set[j];
			j++;
		}

		

	}
	//method to build the deck of the buildings. the deck is not divided yet in the different borrough. the shuffle method is going to divide up the buildings
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
	
	delete[]  lower_manhattan_buildings[7];
	delete[]  midtown_buildings[7];
	delete[]  upper_buildings[7];
	delete[]  queens_buildings[6];
	delete[]  staten_buildings[6];
	delete[]  bronx_buildings[6];
	delete[]  brooklyn_buildings[6];

	delete[] lower_manhattan_units[7];
	delete[] midtown_units[7];
	delete[] upper_units[7];
	delete[] queens_units[6];
	delete[] staten_units[6];
	delete[] bronx_units[6];
	delete[] brooklyn_units[6];


}

Buildings* BU::get_building_from_set(int i, string borrough) {
	if (borrough == "Staten Island") {
		return	staten_buildings[i];
	}
	else if (borrough == "Lower Manhattan") {
		return 	lower_manhattan_buildings[i];
	}
	else if (borrough == "Bronx") {
		return bronx_buildings[i];
	}
	else if (borrough == "Queens") {
		return queens_buildings[i];
	}
	else if (borrough == "Brooklyn") {
		return brooklyn_buildings[i];
	}
	else if (borrough == "Mid Manhattan") {
		return midtown_buildings[i];
	}
	else if (borrough == "Upper Manhattan") {
		return upper_buildings[i] ;
	}


	
}
Units* BU:: get_unit_from_set(int i, string borrough) {
	if (borrough == "Staten Island") {
		return staten_units[i];
	}
	else if (borrough == "Lower Manhattan") {
		return lower_manhattan_units[i];
	}
	else if (borrough == "Bronx") {
		return bronx_units[i];
	}
	else if (borrough == "Queens") {
		return queens_units[i];
	}
	else if (borrough == "Brooklyn") {
		return brooklyn_units[i];
	}
	else if (borrough == "Mid Manhattan") {
		return midtown_units[i];
	}
	else if (borrough == "Upper Manhattan") {
		return upper_units[i];
	}


}