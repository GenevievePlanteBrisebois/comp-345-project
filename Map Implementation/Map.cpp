#include <iostream>
#include <vector>
#include "Map.h"
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include "Borough.h"

/*
	Map class that contains graph data structure and map loader
	By: Batoul Yehia
	ID: 40010912
*/
using namespace std;
using std::string;

int numNodes;
vector<string> *adjList;

Borough * borough [11];

//hard code of borough done by Genevieve Plante-Brisebois 40003112

borough[0] = new Borough(false, "Staten Island", "");
borough[1] = new Borough(false, "Staten Island", "");
borough[2] = new Borough(false, "Bronx", "");
borough[3] = new Borough(false, "Bronx", "");
borough[4] = new Borough(false, "Queens", "");
borough[5] = new Borough(false, "Queens", "");
borough[6] = new Borough(false, "Brooklyn", "");
borough[7] = new Borough(false, "Brooklyn", "");
borough[8] = new Borough(false, "Lower Manhattan", "");
borough[9] = new Borough(false, "Mid Manhattan", "");
borough[10] = new Borough(false, "Upper Manhattan", "");
Borough* Map::getBorough(int i) {
	return borough[i];
}

void Map::setBorough(int i, bool status, string name) {
	borough[i].setStatus(status);
}


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
void Map::addEdge(vector<string> adj[], int src, string dest)
{
	adjList[src].push_back(dest);
}


//prints the map of New York.
void Map::printMap(vector<string> adj[], int N, string nodeList[]) {
	for (int i = 0; i < N; i++) {
		cout << "The regions connected to " << nodeList[i] << " are: " << endl;
		for (auto v : adjList[i]) {
			cout << v;
			cout << endl;
		}
		cout << endl;
	}
}


//Destructor
Map::~Map() {
	adjList = NULL;
	delete[] adjList;
}


//converts a map text file into a graph data structure
void Map::mapLoader(string filename) {

	string line;
	ifstream file(filename);

	//store the entire line in an array
	vector <string> firstElements;

	//first space in every line
	int firstEl = NULL;
	string firstWord;

	//looks for the first space as well, in order to retain the rest of the string
	int secondEl = NULL;

	//first word in every line
	int lengthOfLine;
	string restOfString;
	vector <string> edgesList;

	//read the text file, store the first word in a vector
	//also while reading the file, store the rest of the string in another vector
	while (getline(file, line)) {
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

	//splits the rest of the string and stores them in the Adjacency List
	//Also prints out the node-edge connections
	for (unsigned i = 0; i < firstElements.size(); i++) {
		cout << "The regions connected to " << firstElements[i] << " are:" << endl;
		stringstream data(edgesList[i]);
		string edge;
		splittedEdges.clear();

		while (getline(data, edge, ' ')) {
			splittedEdges.push_back(edge);
		}

		for (unsigned j = 0; j < splittedEdges.size(); j++) {
			addEdge(adjList, i, splittedEdges[j]);
			for (auto v : adjList[i]) {
				cout << v;
				cout << endl;
			}
		}
	}
}
