//written by Genevieve Plante-Brisebois 40003112 comp 345 fall 2018

#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Buildings {
public:
	Buildings();
	Buildings(string type, int durability, int reward, string reward_type);
	~Buildings();
	int getDurability();
	int getReward();
	string getType();
	string getRewardType();
	void setDurability(int dur);
	void setReward(int rew);
	void setType(string t);
	void setRewardType(string t);

	Buildings* create_hospital_1();
	Buildings* create_hospital_2();
	Buildings* create_hospital_3();
	Buildings* create_power_plant_1();
	Buildings* create_power_plant_2();
	Buildings* create_power_plant_3();
	Buildings* create_high_rise_1();
	Buildings* create_high_rise_2();
	Buildings* create_high_rise_3();

};

