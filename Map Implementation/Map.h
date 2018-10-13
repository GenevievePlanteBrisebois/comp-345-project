#pragma once
#include <string>
#include <vector>
#include <iostream>


using namespace std;
class Map
{
public:
	Map(int V);
	Map();
	void addEdge(vector<string> adjList[], int src, string dest);
	void printMap(vector<string> adj[], int N, string nodeList[]);
	void mapLoader(string filename, vector <string> adj[]);
	~Map();
	//void openFile(string filename);
};




