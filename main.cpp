#include "mazeSolver2.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("smallGhost.txt");	
	MazeSolver *solution = new MazeSolver(maze); 

	Node * final = solution->Astar();
	cout << "A* Nodes expanded: " << solution->getAstarExpandedNodes() << " A* Total Path Length:" << solution->getAstarCost() << endl;
	maze->solveMaze(final, "smallGhostAstar.txt");
}
