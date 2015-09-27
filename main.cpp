#include "mazeSolver2.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("bigMaze.txt");	
	MazeSolver2 *solution = new MazeSolver2(maze); 


	Node *final = solution->GBFS();
	cout << "GBFS Nodes expanded: " << solution->getGBFSExpandedNodes() << " GBFS Total Path Length:" << solution->getGBFSCost() << endl;
	maze->solveMaze(final, "bigMazeGBFS2.txt");

	final = solution->Astar();
	cout << "A* Nodes expanded: " << solution->getAstarExpandedNodes() << " A* Total Path Length:" << solution->getAstarCost() << endl;
	maze->solveMaze(final, "bigMazeAstar2.txt");
}
