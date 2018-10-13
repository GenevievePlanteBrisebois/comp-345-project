#include <iostream>
#include <vector>
#include "Map.h"
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <list>


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

//
void Map::mapLoader(string filename, vector<string> adj[]) {
	//ifstream file;
	//string fileName;
	int count = 0;
	string line;
	//string arr[];
	

	ifstream file(filename);
	/*try {
		file.open(filename);
	}
	catch (exception e) {
		cout << "Could not open file.";
	}*/
	
	//store the entire line in an array
	vector <string> firstElements;
	
	int firstEl = NULL;
	string firstWord;

	//int count = 0;
	//int cont = 0;
	int lengthOfLine;
	string restOfString;
	vector <string> edgesList;

	int secondEl = NULL;

	while (getline(file,line)) {
			//storing the first word in an array (aka the nodes)
			firstEl = line.find(" ");
			firstWord = line.substr(0, firstEl);
			firstElements.push_back(firstWord);

			secondEl = line.find(" ");
			if (secondEl != -1) {
				
				lengthOfLine = line.length();

				restOfString = line.substr(secondEl + 1, lengthOfLine - 1);
				edgesList.push_back(restOfString);
			}
			else {

				edgesList.push_back("none");
			}
		
	}

		vector<string> splittedEdges;
		for (int i = 0; i < sizeof(firstElements); i++) {
			//for (auto x : firstElements[i]) {
				stringstream data(edgesList[i]);
				string edge;
				splittedEdges.clear();

				while (getline(data, edge, ' ')) {
					splittedEdges.push_back(edge);
				}

				for (int j = 0; j < sizeof(splittedEdges); ++j) {
					//for (auto y : splittedEdges[j]) {
						addEdge(adj, i, splittedEdges[j]);
					//}
				}

			//}
		}
	//so now the entire file is saved into an array
	//NEXT STEP: create a list of all the first elements in the array
	//and then, for every element that isn't zero, add them into the adjacency list
	
	
	

}






