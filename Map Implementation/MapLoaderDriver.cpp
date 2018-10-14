#include <iostream>
#include <vector>
#include "Map.h"
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <list>


using namespace std;
vector<string> adjList[];


int main22() {
	int count = 0;
	string fileName;
	string line;
	ifstream file("map.txt");

	while (getline(file, line)) {
		count++;
	}
	Map m2(count);
	m2.mapLoader("map.txt",adjList);

	return 0;
}