#include <iostream>
#include <vector>
#include "Map.h"
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <list>
/*
	A driver to test the map loader
	By: Batoul Yehia
	ID: 40010912
*/

using namespace std;
vector<string> adjList[];


int main2() {
	int count = 0;
	string line;
	//read through a file to get the number of lines
	ifstream file("map.txt");
	while (getline(file, line)) {
		count++;
	}

	//create a map object with the number of lines 
	//of the text file (represents number of nodes)
	Map m2(count);

	//loads the map into a graph data structure
	m2.mapLoader("map.txt", adjList);

	return 0;
}