#include <iostream>
#include "GameEngine.h"

using namespace std;

int main() {
	GameEngine s;

	s.SelectPlayers();
	s.LoadMap();
	s.BuildCards();
	s.BuildBuildings();
	s.BuildTokens();

	return 0;
}