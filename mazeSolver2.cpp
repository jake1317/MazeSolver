#include "mazeSolver2.h"
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>

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


Node* MazeSolver2::Astar(){
	// Initialize Tree
	Astar_tree = new Tree(maze->getStart().x, maze->getStart().y);
	Node * root = Astar_tree->get_root();
	root->distance = heuristic(root->x, root->y,root);
	root->pathCost = 0;

	// Create frontier
	priority_queue<Node*, vector<Node*>, indirect_compare> front;
	front.push(root);
	
	// Create visited Array
	bool ** visited = new bool*[maze->getWidth()];
	for(int i = 0;i<maze->getWidth();i++){
		visited[i] = new bool[maze->getHeight()];
		for(int j = 0;j<maze->getHeight();j++){
			visited[i][j] = false;
		}
	}

	// Iterate through maze
	while(front.size() > 0){
		Node * current = front.top();
		front.pop();

		Astar_expandedNodes++;
		int x = current->x;
		int y = current->y;
		// Don't ejpand if visited
		visited[x][y] = true;
		
		// Return if you get to the goal
		if(maze->atEnd(x, y)){
			Astar_cost = computePathCost(current);
			return current;
		}
		Node * child = NULL;
		// Right Dir (0)
		if(maze->canMove(x, y, 0) && !visited[x+1][y]){
			child = GBFS_tree->insert(current, x+1, y);
			child->distance = heuristic(x+1, y, child);
			child->pathCost = computePathCost(child);
			front.push(child);
		}

		// Up Dir (1)
		if(maze->canMove(x, y, 1) && !visited[x][y-1]){
			child = GBFS_tree->insert(current, x, y-1);
			child->distance = heuristic(x, y-1, child);
			child->pathCost = computePathCost(child); 
			front.push(child);
		}

		// Left Dir (2)
		if(maze->canMove(x, y, 2) && !visited[x-1][y]){
			child = GBFS_tree->insert(current, x-1, y);
			child->distance = heuristic(x-1, y, child);
			child->pathCost = computePathCost(child);
			front.push(child);
		}

		// Down Dir (3)
		if(maze->canMove(x, y, 3) && !visited[x][y+1]){
			child = GBFS_tree->insert(current, x, y+1);
			child->distance = heuristic(x, y+1, child);
			child->pathCost = computePathCost(child);
			front.push(child);
		}
	}
	return NULL;
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
			pathCost+=2;
		else 
			pathCost+=3;
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
	else if(par->y == current->y && (par->x+1)==current->x)
		newdir=2;
	else if(par->y == current->y && (par->x-1)==current->x)
		newdir=0;
	else if((par->y+1) == current->y && (par->x)==current->x)
		newdir=1;
	else
		newdir=3;
	return newdir;
}

int MazeSolver2::heuristic(int x, int y, Node* cur){
	int turns, dir = facing(cur, cur->parent);
	int x_dist = maze->getEnd().x - x;
	int y_dist = maze->getEnd().y - y;
/*	
	if((x_dist > 0 && y_dist > 0 && dir != 0 && dir != 3) || (x_dist > 0 && y_dist < 0 && dir != 0 && dir != 1)
	 ||(x_dist < 0 && y_dist > 0 && dir != 2 && dir != 3) || (x_dist < 0 && y_dist < 0 && dir != 2 && dir != 1))  
		turns = 2;
	else if((x_dist == 0 && y_dist > 0 && dir == 3) || (x_dist == 0 && y_dist < 0 && dir == 1) ||
		(x_dist < 0 && y_dist == 0 && dir == 2) || (x_dist > 0 && y_dist == 0 && dir == 0))
		turns = 0;
	else
		turns = 1;		
	return turns + 2*(abs(x_dist) + abs(y_dist));
*/	return abs(x_dist) + abs(y_dist);
}

