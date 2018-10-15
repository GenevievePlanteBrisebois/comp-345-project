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

class Units
{
public:
	Units();
	Units(string type, int durability, int reward, string reward_type);
	~Units();

	string getType();
	int getDurability();
	int getReward();
	string getRewardType();
	void setType(string t);
	void setReward(int r);
	void setDurability(int d);
	void setRewardType(string rt);


	Units* create_infantry();
	Units* create_jet();
	Units* create_tank();
};

class BU {
	BU();
	~BU();

	Units* destroy_building(int damage, Buildings* building);
	void destroy_unit(Units* a);
	void build_building_deck();
	void shuffle(); 

};

