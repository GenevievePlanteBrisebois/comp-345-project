//written by Genevieve Plante-Brisebois 40003112 comp 345 fall 2018

#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;


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