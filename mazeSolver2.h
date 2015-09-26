#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "maze.h"
#include "tree.h"

class MazeSolver2 : Public MazeSolver
{
public:
	
private:
	int facing(Node *current, Node *par);
	int computePathCost(Node *leaf);
};
#endif
