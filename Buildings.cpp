//file created by Genevieve Plante-Brisebois 40003112 for comp 345 fall 2018

#include <iostream>
#include <cstdlib>
#include "Buildings.h"

using namespace std;

//class that forms the buildings

int durability;
string type;
string reward_type;
int reward;
string types[3] = { "hospital", "high rise", "power plant" };
Buildings* building;



Buildings::Buildings()
{
}

Buildings::Buildings(string t, int dur, int r, string reward_t) {
	durability = dur;
	reward = r;
	reward_type = reward_t;
	type = t;

}
Buildings::~Buildings()
{
	delete building;
}
	//make getters and setter
	int Buildings::getDurability() {
		return durability;
	}
	int Buildings::getReward() {
		return reward;
	}
	string Buildings::getType() {
		return type;
	}
	string Buildings::getRewardType() {
		return reward_type;
	}
	void Buildings::setDurability(int dur) {
		durability = dur;
	}
	void Buildings::setReward(int rew) {
		reward = rew;
	}
	void Buildings::setType(string t) {
		type = t;
	}
	void Buildings::setRewardType(string t) {
		reward_type = t;
	}




	//method to create hospital level 1
	Buildings* Buildings::create_hospital_1() {
		Buildings* hospital = new Buildings(types[0], 1, 1, "heal");
		return hospital;
	}
	//method to create hospital level2
	Buildings* Buildings::create_hospital_2() {
		Buildings* hospital = new Buildings(types[0], 2, 2, "heal");
		return hospital;
	}
	//method to create hospital level 3
	Buildings* Buildings::create_hospital_3() {
		Buildings* hospital = new Buildings(types[0], 3, 3, "heal");
		return hospital;
	}
	//method to create power plant level1
	Buildings* Buildings::create_power_plant_1() {
		Buildings* power_plant = new Buildings(types[2], 1, 1, "energy");
		return power_plant;
	}
	//method to create power plant level 2
	Buildings* Buildings::create_power_plant_2() {
		Buildings* power_plant = new Buildings(types[2], 2, 2, "energy");
		return power_plant;
	}
	//method to create power plant level 3
	Buildings* Buildings::create_power_plant_3() {
		Buildings* power_plant = new Buildings(types[2], 3, 3, "energy");
		return power_plant;
	}
	//method to create high rise level 1
	Buildings* Buildings::create_high_rise_1() {
		Buildings* high_rise = new Buildings(types[1], 1, 1, "victory point");
		return high_rise;
	}
	//method to create high rise level2
Buildings* Buildings::create_high_rise_2() {
		Buildings* high_rise = new Buildings(types[1], 2, 2, "victory point");
		return high_rise;
	}
	//method to create high rise level 3
Buildings* Buildings::create_high_rise_3() {
		Buildings* high_rise = new Buildings(types[1], 3, 3, "victory point");
		return high_rise;
	}




