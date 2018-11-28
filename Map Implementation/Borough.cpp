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
	bStatus = stat;
	bName = n;
	player_name = name;
}
Borough::~Borough()
{

}
/*
borough[0] = new Borough(false, "Staten Island", "");
borough[1] = new Borough(false, "Staten Island", "");
borough[2] = new Borough(false, "Bronx", "");
borough[3] = new Borough(false, "Bronx", "");
borough[4] = new Borough(false, "Queens", "");
borough[5] = new Borough(false, "Queens", "");
borough[6] = new Borough(false, "Brooklyn", "");
borough[7] = new Borough(false, "Brooklyn", "");
borough[8] = new Borough(false, "Lower Manhattan", "");
borough[9] = new Borough(false, "Mid Manhattan", "");
borough[10] = new Borough(false, "Upper Manhattan", "");
*/

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
