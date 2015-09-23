#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "tree.h"
#include "maze.h"



class MazeSolver
{
public:
	
	MazeSolver(Maze *newMaze);
	
	~MazeSolver();
	
	Node* BFS();
	
	Node* DFS();
	
	Node* GBFS();
		
	Node* Astar();
	
private:
	
	int heuristic(int x, int y);

	Maze * maze;

	Tree* BFS_tree;
	Tree* DFS_tree;
	Tree* Astar_tree;
	Tree* GBFS_tree;
};
#endif
