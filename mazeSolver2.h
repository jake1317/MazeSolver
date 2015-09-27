#ifndef MAZE_SOLVER2_H
#define MAZE_SOLVER2_H

#include "mazeSolver.h"

class MazeSolver2 : public MazeSolver
{
public:
	

    MazeSolver2(Maze *newMaze);
	
	~MazeSolver2();
private:
	int facing(Node *current, Node *par);
	int computePathCost(Node *leaf);
	int heuristic(int x, int y);
};
#endif
