#include "mazeSolver.h"
#include <iostream>

int main(){
	Maze * maze = new Maze("bigMaze.txt");
	MazeSolver *mazeSolve = new MazeSolver(maze);
	mazeSolve->BFS();
	mazeSolve->DFS();
}
