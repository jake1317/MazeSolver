#include "maze.h"
#include <iostream>
#include <vector>

using namespace std;

Maze::Maze(string filename){
	vector<string> * file = readFile(filename);
	int *** maze = parseMaze(file);
}

Maze::~Maze(){
	cout << "lolbye" << endl;
}

vector<string> * Maze::readFile(string filename){
	ifstream mazeFile;
	mazeFile.open(filename);
	vector<string> * fileLines = new vector<string>();
	string line;
	while(mazeFile.is_open() && getline(mazeFile, line)){
		fileLines->push_back(line);
	}
	return fileLines;
}

int *** Maze::parseMaze(vector<string> * maze){
	return NULL;
}
