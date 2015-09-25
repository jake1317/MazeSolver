#include "mazeSolver.h"
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>

using namespace std;

MazeSolver::MazeSolver(Maze *newMaze){
	BFS_tree = NULL;
	DFS_tree = NULL;
	Astar_tree = NULL;
	GBFS_tree = NULL;
	maze = newMaze;
}

MazeSolver::~MazeSolver()
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

Node* MazeSolver::BFS()
{
	queue<Node*> frontier;
	BFS_tree = new Tree(maze->getStart().x, maze->getStart().y);
	frontier.push(BFS_tree->get_root());
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
		if(maze->canMove(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = BFS_tree->insert(here,here->x+1,here->y);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up and checking if at solution
		if(maze->canMove(here->x,here->y,1) && !visited[here->x][here->y-1])
		{
			next = BFS_tree->insert(here,here->x,here->y-1);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
		//traveling left and checking if at solution
		if(maze->canMove(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = BFS_tree->insert(here,here->x-1,here->y);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down and checking if at solution
		if(maze->canMove(here->x,here->y,3) && !visited[here->x][here->y+1])
		{
			next = BFS_tree->insert(here,here->x,here->y+1);
			if(maze->atEnd(next->x, next->y))
				return next;
			frontier.push(next);
			visited[here->x][here->y+1] = true;
		}
	}
	return here;
}

    
Node* MazeSolver::DFS()
{
	stack<Node*> frontier;
	DFS_tree = new Tree(maze->getStart().x, maze->getStart().y);
	frontier.push(DFS_tree->get_root());
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
		here = frontier.top();
		frontier.pop();
		//traveling right
		if(maze->canMove(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = DFS_tree->insert(here,here->x+1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up 
		if(maze->canMove(here->x,here->y,1) && !visited[here->x][here->y-1])
		{
			next = DFS_tree->insert(here,here->x,here->y-1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
		//traveling left
		if(maze->canMove(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = DFS_tree->insert(here,here->x-1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down
		if(maze->canMove(here->x,here->y,3) && !visited[here->x][here->y+1])
		{
			next = DFS_tree->insert(here,here->x,here->y+1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y)
				return next;
			frontier.push(next);
			visited[here->x][here->y+1] = true;
		}
    }
	return here;
}


Node* MazeSolver::GBFS(){
	// Initialize Tree
	GBFS_tree = new Tree(maze->getStart().x, maze->getStart().y);
	Node * root = GBFS_tree->get_root();
	root->distance = heuristic(root->x, root->y);

	// Create frontier
	vector<Node*> frontier;
	frontier.push_back(root);
	make_heap(frontier.begin(), frontier.end());
	
	// Create visited Array
	bool ** visited = new bool*[maze->getWidth()];
	for(int i = 0;i<maze->getWidth();i++){
		visited[i] = new bool[maze->getHeight()];
		for(int j = 0;j<maze->getHeight();j++){
			visited[i][j] = false;
		}
	}

	// Iterate through maze
	while(frontier.size() > 0){
		pop_heap(frontier.begin(), frontier.end());
		Node * current = frontier.back();
		frontier.pop_back();
		int x = current->x;
		int y = current->y;
		cout << "(" << x << ", " << y << ")" << endl;
		// Don't expand if visited
		if(visited[x][y]){
			continue;
		}else{
			visited[x][y] = true;
		}
		
		// Return if you get to the goal
		if(maze->atEnd(x, y)){
			return current;
		}

		// Right Dir (0)
		if(maze->canMove(x+1, y, 0)){
			Node * child = GBFS_tree->insert(current, x+1, y);
			child->distance = heuristic(x+1, y);
			frontier.push_back(child);
			push_heap(frontier.begin(), frontier.end());
		}

		// Up Dir (1)
		if(maze->canMove(x, y-1, 1)){
			Node * child = GBFS_tree->insert(current, x, y-1);
			child->distance = heuristic(x, y-1);
			frontier.push_back(child);
			push_heap(frontier.begin(), frontier.end());
		}

		// Left Dir (2)
		if(maze->canMove(x-1, y, 2)){
			Node * child = GBFS_tree->insert(current, x-1, y);
			child->distance = heuristic(x-1, y);
			frontier.push_back(child);
			push_heap(frontier.begin(), frontier.end());
		}

		// Down Dir (3)
		if(maze->canMove(x, y+1, 1)){
			Node * child = GBFS_tree->insert(current, x, y+1);
			child->distance = heuristic(x, y+1);
			frontier.push_back(child);
			push_heap(frontier.begin(), frontier.end());
		}
	}
	/*
	 * Make root at start
	 * make visited array
	 *
	 *  loop:
	 * 		pop minHeap
	 * 		check visited
	 * 		check if its at goal
	 * 			return if goal
	 * 		add frontier to heap/tree
	 */
}


int MazeSolver::heuristic(int x, int y){
	return abs(maze->getEnd().x - x) + abs(maze->getEnd().y - y);
}
