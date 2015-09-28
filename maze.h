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
		bool canMove(int x, int y, int dir, int n);
	    void solveMaze(Node *leaf, string name, int nodes, int path);
		// Accessors
		int getHeight(){ return height; };
		int getWidth(){ return width; };
		coordinate getStart(){ return start; };
		struct coordinate getGhostPos(int n);
		bool atEnd(int x, int y);
		coordinate getEnd(){ return end; };
		int zigZag(int width, int initOffset, int n);
	private:
		vector<string> * readFile(string filename);
		bool ** parseMaze(vector<string> * maze);
		void discoverGhost();
		int height;
		int width;
		coordinate start;
		coordinate end;
		coordinate ghost;
		int leftGhostWall;
		int rightGhostWall;
		bool ** maze;
};
#endif
