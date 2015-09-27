#include "mazeSolver2.h"

MazeSolver2::MazeSolver2(Maze *newMaze):MazeSolver(newMaze){
	BFS_tree = NULL;
	DFS_tree = NULL;
	Astar_tree = NULL;
	GBFS_tree = NULL;
	maze = newMaze;
	BFS_expandedNodes = 0;
	DFS_expandedNodes = 0;
	GBFS_expandedNodes = 0;
	Astar_expandedNodes = 0;
}

MazeSolver2::~MazeSolver2()
{
	delete BFS_tree;
	delete DFS_tree;
	delete Astar_tree;
	delete GBFS_tree;
	delete maze;
	BFS_tree = NULL;
	DFS_tree = NULL;
	Astar_tree = NULL;
	GBFS_tree = NULL;
	maze = NULL;
}

int MazeSolver2::computePathCost(Node * leaf){
	Node * current = leaf;
	Node * par = current->parent;
	Node * parpar = par->parent;
	int dir, newdir, pathCost = 0;
	
	while(current){
		dir = facing(par, parpar);
		newdir = facing(current, par);
			
		if(dir == newdir)
			pathCost++;
		else 
			pathCost+=2;
		current = current->parent;
		if(par != NULL)
			par = par->parent;
		if(parpar != NULL)
			parpar = parpar->parent;
	}
	return pathCost;
}

int MazeSolver2::facing(Node *current, Node *par)
{
	int newdir;
	if(par == NULL)
		newdir = 0;
	if(par->y == current->y && (par->x+1)==current->x)
		newdir=2;
	else if(par->y == current->y && (par->x-1)==current->x)
		newdir=0;
	else if((par->y+1) == current->y && (par->x)==current->x)
		newdir=1;
	else
		newdir=3;
	return newdir;
}

int MazeSolver2::heuristic(int x, int y){
	int i, walls = 0;
	for( i = x; i <= maze->getEnd().x; i++)
	{
		if(!maze->canMove(i,y,-1))
			walls++;
	}
	for(i = x; i >= maze->getEnd().x; i--)
	{
		if(!maze->canMove(i,y,-1))
			walls++;
	}
	for(i = y; i <= maze->getEnd().y; i++)
	{
		if(!maze->canMove(maze->getEnd().x,i,-1))
			walls++;
	}
	for(i = y; i >= maze->getEnd().y; i--)
	{
		if(!maze->canMove(maze->getEnd().x,i,-1))
			walls++;
	}
	return abs(maze->getEnd().x - x) + walls + abs(maze->getEnd().y - y);

}

