#include <iostream>
#include <vector>
#include "Map.h"
#include <string>


using namespace std;
using std::string;


int numNodes;
vector<string> *adjList;

//Constructor
//creation of map requires the number of nodes existing in the map.
Map::Map(int nodes)
{
	numNodes = nodes;
	adjList = new vector<string>[nodes];
}

//Default constructor
Map::Map() {
}

//Adds an edge to the adjacency list of a node.
/*
Since this is a vector of strings, the source takes the location of the region within the array of regions.
It pushes a string of the destination within the vector of strings. 
*/
void Map::addEdge(vector<string> adjList[], int src, string dest)
{
	adjList[src].push_back(dest);
}


//prints the map of New York.
void Map::printMap(vector<string> adj[], int N, string nodeList[]) {
	for (int i = 0; i < N; i++) {
		cout << "The regions connected to " << nodeList[i] << " are: " << endl;
		for (auto v : adj[i]) {
			cout << v;
			cout << endl;
		}
		cout << endl;
	}
}

//Destructor
Map::~Map() {
	delete[] adjList;
}





