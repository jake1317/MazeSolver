#include "mazeSolver.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("openMaze.txt");	
	MazeSolver *solution = new MazeSolver(maze);

  	Node *final = solution->BFS();
	cout << "BFS Nodes expanded: " << solution->getBFSExpandedNodes() << " BFS Total Path Length:" << solution->getBFSCost() << endl;
    maze->solveMaze(final, "openMazeBFS.txt");

	final = solution->DFS();
	cout << "DFS Nodes expanded: " << solution->getDFSExpandedNodes() << " DFS Total Path Length:" << solution->getDFSCost() << endl;
    maze->solveMaze(final, "openMazeDFS.txt");

	final = solution->GBFS();
	cout << "GBFS Nodes expanded: " << solution->getGBFSExpandedNodes() << " GBFS Total Path Length:" << solution->getGBFSCost() << endl;
	maze->solveMaze(final, "openMazeGBFS.txt");

	final = solution->Astar();
	cout << "A* Nodes expanded: " << solution->getAstarExpandedNodes() << " A* Total Path Length:" << solution->getAstarCost() << endl;
	maze->solveMaze(final, "openMazeAstar.txt");
}
