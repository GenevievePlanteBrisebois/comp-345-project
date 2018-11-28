#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Borough.h"

/*
	Map class header
	By: Batoul Yehia
	ID: 40010912
*/
using namespace std;
class Map : public Borough
{
public:
	Map(int V);
	Map();
	void addEdge(vector<string> adjList[], int src, string dest);
	void printMap(vector<string> adj[], int N, string nodeList[]);
	void mapLoader(string filename);
	void setBorough(int i, bool status, string playerName);
	Borough *getBorough(int i);
	//void setBorough(int i, bool status);
	~Map();
};
