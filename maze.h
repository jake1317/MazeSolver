#ifndef MAZE_H
#define MAZE_H

#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include "tree.h"
using namespace std;

class Maze{
	struct coordinate{
		int x;
		int y;
	};
	public:
		// Constructors n stuff
		Maze(string filename);
		~Maze();

		// Misc Functions
		void printMaze();
		bool canMove(int x, int y, int dir);
	        void solveMaze(Node *leaf, string name, int nodes, int path);
		// Accessors
		int getHeight(){ return height; };
		int getWidth(){ return width; };
		coordinate getStart(){ return start; };
		bool atEnd(int x, int y);
		coordinate getEnd(){ return end; };
	private:
		vector<string> * readFile(string filename);
		bool ** parseMaze(vector<string> * maze);
		int height;
		int width;
		coordinate start;
		coordinate end;
		coordinate ghost;
		int ghostDir;
		bool ** maze;
};
#endif
