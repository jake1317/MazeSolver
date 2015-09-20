#include "maze.h"
#include <iostream>
#include <vector>

using namespace std;

Maze::Maze(string filename){
	// Get file vector
	vector<string> * file = readFile(filename);
	// Assign Height and Width
	height = file->size();
	width = (int) (*file)[0].length() - 1;
	// Get maze array
	maze = parseMaze(file);
	delete(file);
}

Maze::~Maze(){
	for(int x = 0;x<width;x++){
		delete(maze[x]);
	}
	delete(maze);
}

vector<string> * Maze::readFile(string filename){
	ifstream mazeFile;
	mazeFile.open(filename);
	vector<string> * fileLines = new vector<string>();
	string line;
	while(mazeFile.is_open() && getline(mazeFile, line)){
		fileLines->push_back(line);
	}
	mazeFile.close();
	return fileLines;
}

bool ** Maze::parseMaze(vector<string> * maze){
	bool ** outputMaze = new bool*[this->width];
	// Iterate on x
	for(int x = 0;x < this->width; x++){
		outputMaze[x] = new bool[this->height];
		// Iterate on y
		for(int y = 0;y < this->height; y++){
			// Get important chars
			char currChar = (*maze)[y].at(x);
			// Assign boolean
			if(currChar == ' ' || currChar == 'P' || currChar == '.'){
				outputMaze[x][y] = true;
			} else {
				outputMaze[x][y] = false;
			}
			// Assign start and end points
			if(currChar == 'P'){
				end.x = x;
				end.y = y;
			} else if(currChar == '.'){
				start.x = x;
				start.y = y;
			}
		}
	}
	return outputMaze;
}

void Maze::printMaze(){
	cout << "Start: (" << start.x << ", " << start.y << ")" << endl;
	cout << "End: (" << end.x << ", " << end.y << ")" << endl;
	for(int y = 0;y < this->height;y++){
		for(int x = 0;x < this->width;x++){
			if(start.x == x && start.y == y){
				cout << '.';
				continue;
			} else if(end.x == x && end.y == y){
				cout << 'P';
				continue;
			}
			if(maze[x][y]){
				cout << ' ';
			} else{
				cout << '%';
			}
		}
		cout << endl;
	}
}
