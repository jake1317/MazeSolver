#include "maze.h"
#include <iostream>

int main(){
	Maze * maze = new Maze("bigMaze.txt");
	maze->printMaze();
	delete(maze);
}
