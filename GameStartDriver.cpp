#include <iostream>
#include "StartGame.h"

using namespace std;

int main() {
	StartGame s;

	s.SelectPlayers();
	s.LoadMap();
	s.BuildCards();
	s.BuildBuildings();
	s.BuildTokens();

	return 0;
}