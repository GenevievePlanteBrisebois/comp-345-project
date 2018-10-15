#pragma once
#include "Map.h"
#include <iostream>
#include <vector>
#include <string>

/*
	A driver to test the graph data structure for the maps
	By: Batoul Yehia
	ID: 40010912
*/
using namespace std;

const int N = 7;
vector<string> adjacencyList[N];

int main() {
	string buroughList[7] = { "Staten Island", "Lower Manhattan", "Bronx", "Queens", "Brooklyn", "Mid Manhattan", "Upper Manhattan" };
	//creation of a map with seven nodes
	Map m(7);

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

	//print map
	m.printMap(adjacencyList, N, buroughList);

	return 0;
}