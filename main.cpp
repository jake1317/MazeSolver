#include "mazeSolver.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("openMaze.txt");	
	MazeSolver *solution = new MazeSolver(maze);
  	Node *final = solution->BFS();
    maze->solveMaze(final, "openMazeBFS.txt");
}
