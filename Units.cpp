//file created by Genevieve Plante-Brisebois 40003112 for comp 345 fall 2018

#include <iostream>
#include <cstdlib>
#include<string>
#include "Units.h"

using namespace std;

//class that forms the units

	
	string unit_type;
	int unit_durability;
	int unit_reward;
	string unit_reward_type;
	Units* unit;
	//setters and getters
	string Units::getType() {
		return unit_type;
	}
	int Units::getDurability() {
		return unit_durability;
	}
	int Units::getReward() {
		return unit_reward;
	}
	string Units::getRewardType() {
		return unit_reward_type;
	}
	void Units::setType(string t) {
		unit_type = t;
	}
	void Units::setReward(int r) {
		unit_reward = r;
	}
	void Units::setDurability(int d) {
		unit_durability = d;
	}
	void Units::setRewardType(string rt) {
		unit_reward_type = rt;
	}


	//methods to create the different types of units

	Units* Units::create_infantry() {
		Units* infantry = new Units("infantry", 2, 1, "heal");
		return infantry;
	}

	Units* Units::create_jet() {
		Units* jet = new Units("jet", 3, 2, "energy");
		return jet;
	}

	Units* Units::create_tank() {
		
		Units* tank = new Units("tank", 4, 3, "victory point");
		return tank;
	}





Units::Units()
{
}

Units::Units(string t, int dur, int r, string reward_t)
{
	unit_type = t;
	unit_durability = dur;
	unit_reward = r;
	unit_reward_type = reward_t;
}

Units::~Units()
{
	delete unit;
}