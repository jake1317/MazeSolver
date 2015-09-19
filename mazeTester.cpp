#include "maze.h"
#include <iostream>

int main(){
	Maze * maze = new Maze("bigMaze.txt");
	cout << "ass" << endl;
	delete(maze);
}
