#include "mazeSolver.h"
#include <queue>
#include <stack>

MazeSolver::MazeSolver(Maze *newMaze){
	BFS_tree = NULL;
	DFS_tree = NULL;
	A*_tree = NULL;
	GBFS_tree = NULL;
	maze = newMaze;
}

MazeSolver::~MazeSolver()
{
	delete BFS_tree;
	delete DFS_tree;
	delete A*_tree;
	delete GBFS_tree;
	if(maze){
		delete(maze);
	}
}

Node* MazeSolver::BFS()
{
	queue<Node*> frontier;
	BFS_tree = new Tree(maze->getStart().x, maze->getStart().y);
	frontier.push(BFS_tree.get_root());
	bool **visited;
	int i, j;
	Node *here;
	Node *next;
	//initalizing the visited array
	visited = new bool*[maze->getWidth()];
	for(i = 0; i < maze->getWidth(); i++)
	{
		visited[i] = new bool[maze->getHeight()];
		for(j=0; j< maze->getHeight(); j++)
			visited[i][j] = false;
	}
	visited[maze->getStart().x][maze->getStart().y] = true;
	
	while(!frontier.empty())
	{
		here = frontier.front();
		frontier.pop();
		//traveling right and checking if at solution
		if(maze->canTravel(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = BFS_tree.insert(here,here->x+1,here->y);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up and checking if at solution
		if(maze->canTravel(here->x,here->y,1) && !visited[here->x][here->y+1])
		{
			next = BFS_tree.insert(here,here->x,here->y+1);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x][here->y+1] = true;
		}
		//traveling left and checking if at solution
		if(maze->canTravel(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = BFS_tree.insert(here,here->x-1,here->y);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down and checking if at solution
		if(maze->canTravel(here->x,here->y,3) && !visited[here->x][here->y-1])
		{
			next = BFS_tree.insert(here,here->x,here->y-1);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
	}
	return DFS_tree.getroot();
}

    
Node* MazeSolver::DFS()
{
	stack<Node*> frontier;
	DFS_tree = new Tree(maze->getStart().x, maze->getStart().y);
	frontier.push(BFS_tree.get_root());
	bool **visited;
	int i, j;
	Node *here;
	Node *next;
	visited = new bool*[maze->getWidth()];
	//initalizing the visited array
	for(i = 0; i < maze->getWidth(); i++)
	{
		visited[i] = new bool[maze->getHeight()];
		for(j=0; j< maze->getHeight(); j++)
			visited[i][j] = false;
	}
	visited[maze->getStart().x][maze->getStart().y] = true;
	
	while(!frontier.empty())
	{
		here = frontier.front();
		frontier.pop();
		//traveling right
		if(maze->canTravel(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = DFS_tree.insert(here,here->x+1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up 
		if(maze->canTravel(here->x,here->y,1) && !visited[here->x][here->y+1])
		{
			next = DFS_tree.insert(here,here->x,here->y+1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x][here->y+1] = true;
		}
		//traveling left
		if(maze->canTravel(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = DFS_tree.insert(here,here->x-1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down
		if(maze->canTravel(here->x,here->y,3) && !visited[here->x][here->y-1])
		{
			next = DFS_tree.insert(here,here->x,here->y-1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
    }
	return DFS_tree.getroot();
}

int MazeSolver::heuristic(int x, int y){
	return 0;
}
