//file created by Genevieve Plante-Brisebois 40003112 for comp 345 fall 2018

#include <iostream>
#include <cstdlib>

using namespace std;

//class that forms the buildings
class Buildings
{
public:
	Buildings();
	Buildings(string type, int durability, int reward, string reward_type);
	~Buildings();
	int durability;
	string type;
	string reward_type;
	int reward;
	string types[3] = { "hospital", "high rise", "power plant" };
	Buildings* building;

	//make getters and setter
	int getDurability() {
		return durability;
	}
	int getReward() {
		return reward;
	}
	string getType() {
		return type;
	}
	string getRewardType() {
		return reward_type;
	}
	void setDurability(int dur) {
		this->durability = dur;
	}
	void setReward(int rew) {
		this->reward = rew;
	}
	void setType(string t) {
		this->type = t;
	}
	void setRewardType(string t) {
		this->reward_type = t;
	}

	


	//method to create hospital level 1
	Buildings* create_hospital_1() {
		Buildings* hospital = new Buildings(types[0], 1, 1, "heal");
		return hospital;
	}
	//method to create hospital level2
	Buildings* create_hospital_2() {
		Buildings* hospital = new Buildings(types[0], 2, 2, "heal");
		return hospital;
	}
	//method to create hospital level 3
	Buildings* create_hospital_3() {
		Buildings* hospital = new Buildings(types[0], 3, 3, "heal");
		return hospital;
	}
	//method to create power plant level1
	Buildings* create_power_plant_1() {
		Buildings* power_plant = new Buildings(types[2], 1, 1, "energy");
		return power_plant;
	}
	//method to create power plant level 2
	Buildings* create_power_plant_2() {
		Buildings* power_plant = new Buildings(types[2], 2, 2, "energy");
		return power_plant;
	}
	//method to create power plant level 3
	Buildings* create_power_plant_3() {
		Buildings* power_plant = new Buildings(types[2], 3, 3, "energy");
		return power_plant;
	}
	//method to create high rise level 1
	Buildings* create_high_rise_1() {
		Buildings* high_rise = new Buildings(types[1], 1, 1, "victory point");
		return high_rise;
	}
	//method to create high rise level2
	Buildings* create_high_rise_2() {
		Buildings* high_rise = new Buildings(types[1], 2, 2, "victory point");
		return high_rise;
	}
	//method to create high rise level 3
	Buildings* create_high_rise_3() {
		Buildings* high_rise = new Buildings(types[1], 3, 3, "victory point");
		return high_rise;
	}

};

Buildings::Buildings()
{
	durability = 0;
	type = "";
	reward_type = "";
	reward = 0;
}

Buildings::Buildings(string type, int durability, int reward, string reward_type) {
	this->durability = durability;
	this->reward = reward;
	this->reward_type = reward_type;
	this->type = type;

}
Buildings::~Buildings()
{
	delete building;
}
//class that forms the units
class Units
{
public:
	Units();
	Units(string type, int durability, int reward, string reward_type);
	~Units();
	string type;
	int durability;
	int reward;
	string reward_type;
	string unit_type[3] = { "infantry", "jet", "tank" };
	Units* unit;
	//setters and getters
	string getType() {
		return type;
	}
	int getDurability() {
		return durability;
	}
	int getReward() {
		return reward;
	}
	string getRewardType() {
		return reward_type;
	}
	void setType(string t) {
		type = t;
	}
	void setReward(int r) {
		reward = r;
	}
	void setDurability(int d) {
		durability = d;
	}
	void setRewardType(string rt) {
		reward_type = rt;
	}


	//methods to create the different types of units

	Units* create_infantry() {
		Units* infantry = new Units(unit_type[0], 2, 1, "heal");
		return infantry;
	}

	Units* create_jet() {
		Units* jet = new Units(unit_type[1], 3, 2, "energy");
		return jet;
	}

	Units* create_tank() {
		Units* tank = new Units(unit_type[2], 4, 3, "victory point");
		return tank;
	}

	

};

Units::Units()
{
	type = "";
	reward = 0;
	durability = 0;
	reward_type = "";

}

Units::Units(string type, int durability, int reward, string reward_type)
{
	this->type = type;
	this->durability = durability;
	this->reward = reward;
	this->reward_type = reward_type;
}

Units::~Units()
{
	delete unit;
}
//class that brings together the units and the buildings
class BU :Units,Buildings
{
public:
	BU ();
	~BU ();
	Buildings* start_set[45];
	Units* unit_set[45];

	//method to damage the building. when a building is destroyed it produces a unit
	//the effect of destroying the building will have to be done in another class to call on the heal, add vp methods of monsters
	Units* destroy_building(int damage, Buildings* building) {

		int dur = building->getDurability();
		int bu = dur - damage;

		if (building->getDurability() == 1) {
			Units* new_unit = create_infantry();
			delete building;
		}
		else if (building->getDurability() == 2) {
			Units* new_unit = create_jet();
			delete building;
		}
		else {
			Units* new_unit = create_tank();
			delete building;
		}

	}
	//the reward will have to be given according to the unit type in the driver
	//method to damage the units when a unit dies it is taken off the board
	void destroy_unit( Units* a) {
		delete a;
	}

	//suffle method for to mix the buildings before we put them on the board
	void shuffle() {
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

		delete[] temp;

	}
	//method to build the deck of the buildings
	void build_building_deck() {
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
};

BU ::BU ()
{
	Buildings* start_set[45];
	Units* unit_set[45];
}

BU ::~BU ()
{
	delete[] start_set;
	delete[] unit_set;
}