#pragma once
#include "Map.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int N = 7;

vector<string> adjacencyList[N];
vector<string> adjList[];

int main() {
	string buroughList[7] = { "Staten Island", "Lower Manhattan", "Bronx", "Queens", "Brooklyn", "Mid Manhattan", "Upper Manhattan" };
	//vector<string> buroughList = { "Staten Island", "Lower Manhattan", "Bronx", "Queens", "Brooklyn", "Mid Manhattan", "Upper Manhattan" };
	//creation of a map object with 7 nodes, each representing a region
	Map m(7);

	int count = 0;
	string fileName;
	string line;
	ifstream file("map.txt");
	
	while (getline(file, line)) {
		count++;
	}
	Map m2(count);

	cout << count;
	//m.mapLoader("map.txt", adjList);



	
	/*
	
	//Adding edges to Staten Island.
	m.addEdge(adjacencyList, 0, buroughList[1]);

	//Adding Edges to Lower Manhattan
	m.addEdge(adjacencyList, 1, buroughList[0]);
	m.addEdge(adjacencyList, 1, buroughList[2]);
	m.addEdge(adjacencyList, 1, buroughList[3]);
	m.addEdge(adjacencyList, 1, buroughList[4]);
	m.addEdge(adjacencyList, 1, buroughList[5]);

	//Adding Edges to Bronx
	m.addEdge(adjacencyList, 2, buroughList[1]);

	//Adding Edges to Queens
	m.addEdge(adjacencyList, 3, buroughList[1]);
	m.addEdge(adjacencyList, 3, buroughList[4]);

	//Adding Edges to Brooklyn
	m.addEdge(adjacencyList, 4, buroughList[1]);
	m.addEdge(adjacencyList, 4, buroughList[3]);

	//Adding Edges to Mid Manhattan
	m.addEdge(adjacencyList, 5, buroughList[0]);
	m.addEdge(adjacencyList, 5, buroughList[2]);
	m.addEdge(adjacencyList, 5, buroughList[3]);
	m.addEdge(adjacencyList, 5, buroughList[4]);
	m.addEdge(adjacencyList, 5, buroughList[6]);

	//Adding Edges to Upper Manhattan
	m.addEdge(adjacencyList, 6, buroughList[0]);
	m.addEdge(adjacencyList, 6, buroughList[2]);
	m.addEdge(adjacencyList, 6, buroughList[3]);
	m.addEdge(adjacencyList, 6, buroughList[4]);
	
	//m.mapLoader("map.txt", adjacencyList);
	//m.printMap(adjacencyList, N, buroughList);
	*/
	
	//m.~Map();
	m2.mapLoader("map.txt", adjList);
	//m2.~Map();
	


	return 0;
}
