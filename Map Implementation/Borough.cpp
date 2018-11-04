/*
class made by Genevieve Plante-Brisebois 40003112
comp 345 fall 2018
*/

#include "Borough.h"
bool status;
string name;


Borough::Borough()
{
    status=false;
    name = "";
}
Borough:: Borough(bool stat, string n){
status =stat;
name = n;

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

bool Borough:: getStatus(){
return status;
}

string Borough:: getName(){
return name;
}
