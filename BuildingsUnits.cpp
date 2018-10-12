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
class BU 
{
public:
	BU ();
	~BU ();

	//method to damage the building
	Units* destroy_building(int damage, Buildings* building) {

		int dur = building->getDurability();
		int bu = dur - damage;




	}

};

BU ::BU ()
{
}

BU ::~BU ()
{
}