/*
class made by Genevieve Plante-Brisebois 40003112
comp 345 fall 2018
*/

#include "Borough.h"
bool status;
string name;
string player_name;

Borough::Borough()
{
    status=false;
    name = "";
	player_name = "";
}
Borough:: Borough(bool stat, string n, string name){
status =stat;
name = n;
player_name = name;
}
Borough::~Borough()
{

}

void Borough:: setStatus(bool stat){
status = stat;
}
void Borough:: setName(string n){
name=n;
}
void Borough::setPlayerName(string name) {
	player_name = name;
}
string Borough::getPlayerName() {
	return player_name;
}

bool Borough:: getStatus(){
return status;
}

string Borough:: getName(){
return name;
}
