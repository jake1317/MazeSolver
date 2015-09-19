#include "maze.h"
#include <iostream>

using namespace std;

Maze::Maze(string filename){
	cout << "ayy" << endl;
	ifstream mazeFile;
	mazeFile.open(filename);
	string line;
	while(mazeFile.is_open() && getline(mazeFile, line)){
		cout << line << endl;
	}
}

Maze::~Maze(){
	cout << "lolbye" << endl;
}
