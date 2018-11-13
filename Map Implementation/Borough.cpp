/*
class made by Genevieve Plante-Brisebois 40003112
comp 345 fall 2018
*/

#include "Borough.h"
#include <string>

bool bStatus;
string bName;
string player_name;

Borough::Borough()
{
    bStatus=false;
    bName = "";
	player_name = "";
}
Borough:: Borough(bool stat, string n, string name){
	bStatus =stat;
	name = n; //???
	player_name = name;
}
Borough::~Borough()
{

}

void Borough:: setBoroughStatus(bool stat){
	bStatus = stat;
}
void Borough:: setName(string n){
	bName = n;
}
void Borough::setPlayerName(string name) {
	player_name = name;
}
string Borough::getPlayerName() {
	return player_name;
}

bool Borough:: getBoroughStatus(){
return bStatus;
}

string Borough:: getBName(){
return bName;
}
