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
	BFS_expandedNodes = 0;
	DFS_expandedNodes = 0;
	GBFS_expandedNodes = 0;
	Astar_expandedNodes = 0;

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
		BFS_expandedNodes++;
		//traveling right and checking if at solution
		if(maze->canMove(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = BFS_tree->insert(here,here->x+1,here->y);
			if(maze->atEnd(next->x, next->y)){
				BFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up and checking if at solution
		if(maze->canMove(here->x,here->y,1) && !visited[here->x][here->y-1])
		{
			next = BFS_tree->insert(here,here->x,here->y-1);
			if(maze->atEnd(next->x, next->y)){
				BFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
		//traveling left and checking if at solution
		if(maze->canMove(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = BFS_tree->insert(here,here->x-1,here->y);
			if(maze->atEnd(next->x, next->y)){
				BFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down and checking if at solution
		if(maze->canMove(here->x,here->y,3) && !visited[here->x][here->y+1])
		{
			next = BFS_tree->insert(here,here->x,here->y+1);
			if(maze->atEnd(next->x, next->y)){
				BFS_cost = computePathCost(next);
				return next;
			}
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
		DFS_expandedNodes++;
		//traveling right
		if(maze->canMove(here->x,here->y,0) && !visited[here->x+1][here->y])
		{
			next = DFS_tree->insert(here,here->x+1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y){
				DFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x+1][here->y] = true;
		}
		//traveling up 
		if(maze->canMove(here->x,here->y,1) && !visited[here->x][here->y-1])
		{
			next = DFS_tree->insert(here,here->x,here->y-1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y){
				DFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x][here->y-1] = true;
		}
		//traveling left
		if(maze->canMove(here->x,here->y,2) && !visited[here->x-1][here->y])
		{
			next = DFS_tree->insert(here,here->x-1,here->y);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y){
				DFS_cost = computePathCost(next);
				return next;
			}
			frontier.push(next);
			visited[here->x-1][here->y] = true;
		}
		//traveling down
		if(maze->canMove(here->x,here->y,3) && !visited[here->x][here->y+1])
		{
			next = DFS_tree->insert(here,here->x,here->y+1);
			if(next->x == maze->getEnd().x && next->y == maze->getEnd().y){
				DFS_cost = computePathCost(next);
				return next;
			}
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

		GBFS_expandedNodes++;
		int x = current->x;
		int y = current->y;
		// Don't ejpand if visited
		visited[x][y] = true;
		
		// Return if you get to the goal
		if(maze->atEnd(x, y)){
			GBFS_cost = computePathCost(current);
			return current;
		}
		Node * child = NULL;
		// Right Dir (0)
		if(maze->canMove(x, y, 0) && !visited[x+1][y]){
			child = GBFS_tree->insert(current, x+1, y);
			child->distance = heuristic(x+1, y);
			child->pathCost = 0;
			front.push(child);
		}

		// Up Dir (1)
		if(maze->canMove(x, y, 1) && !visited[x][y-1]){
			child = GBFS_tree->insert(current, x, y-1);
			child->distance = heuristic(x, y-1);
			child->pathCost = 0;
			front.push(child);
		}

		// Left Dir (2)
		if(maze->canMove(x, y, 2) && !visited[x-1][y]){
			child = GBFS_tree->insert(current, x-1, y);
			child->distance = heuristic(x-1, y);
			child->pathCost = 0;
			front.push(child);
		}

		// Down Dir (3)
		if(maze->canMove(x, y, 3) && !visited[x][y+1]){
			child = GBFS_tree->insert(current, x, y+1);
			child->distance = heuristic(x, y+1);
			child->pathCost = 0;
			front.push(child);
		}
	}
	return NULL;
}

Node* MazeSolver::Astar(){
	// Initialize Tree
	Astar_tree = new Tree(maze->getStart().x, maze->getStart().y);
	Node * root = Astar_tree->get_root();
	root->distance = heuristic(root->x, root->y);
	root->pathCost = 0;
	
	// Create visited Array
	bool ** visited = new bool*[maze->getWidth()];
	for(int i = 0;i<maze->getWidth();i++){
		visited[i] = new bool[maze->getHeight()];
		for(int j = 0;j<maze->getHeight();j++){
			visited[i][j] = false;
		}
	}

	// Create frontier
	priority_queue<Node*, vector<Node*>, indirect_compare> front;
	front.push(root);

	// Iterate through maze
	while(front.size() > 0){
		Node * current = front.top();
		front.pop();

		Astar_expandedNodes++;
		int x = current->x;
		int y = current->y;
		
		// Return if you get to the goal
		if(maze->atEnd(x, y)){
			Astar_cost = current->pathCost + 1;
			return current;
		}
	
		visited[x][y] = true;		

		Node * child = NULL;
		// Right Dir (0)
		if(maze->canMove(x, y, 0, current->pathCost) && !visited[x+1][y]){
			child = GBFS_tree->insert(current, x+1, y);
			child->distance = heuristic(x+1, y);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Up Dir (1)
		if(maze->canMove(x, y, 1, current->pathCost) && !visited[x][y-1]){
			child = GBFS_tree->insert(current, x, y-1);
			child->distance = heuristic(x, y-1);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Left Dir (2)
		if(maze->canMove(x, y, 2, current->pathCost) && !visited[x-1][y]){
			child = GBFS_tree->insert(current, x-1, y);
			child->distance = heuristic(x-1, y);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Down Dir (3)
		if(maze->canMove(x, y, 3, current->pathCost) && !visited[x][y+1]){
			child = GBFS_tree->insert(current, x, y+1);
			child->distance = heuristic(x, y+1);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}
	}
	cout << "ayy" << endl;
	return NULL;
}

Node* MazeSolver::AstarNoRSD(){
	// Initialize Tree
	Astar_tree = new Tree(maze->getStart().x, maze->getStart().y);
	Node * root = Astar_tree->get_root();
	root->distance = heuristic(root->x, root->y);
	root->pathCost = 0;
	
	// Create frontier
	priority_queue<Node*, vector<Node*>, indirect_compare> front;
	front.push(root);

	// Iterate through maze
	while(front.size() > 0){
		Node * current = front.top();
		front.pop();

		Astar_expandedNodes++;
		int x = current->x;
		int y = current->y;
		
		// Return if you get to the goal
		if(maze->atEnd(x, y)){
			Astar_cost = current->pathCost + 1;
			return current;
		}
/*	
		cout << "Position: (" << x << ", " << y << ") Level:" << current->pathCost << endl;
		cout << "Ghost: (" << maze->getGhostPos(current->pathCost).x << ", " << maze->getGhostPos(current->pathCost).y << ") Level:" << current->pathCost << endl;
		cout << "Right: " << maze->canMove(x, y, 0, current->pathCost) << " Down: " << maze->canMove(x, y, 1, current->pathCost) << " Left: " << maze->canMove(x, y, 2, current->pathCost) << " Up: " << maze->canMove(x, y, 3, current->pathCost) << endl << endl;
		*/
		//cout << current->pathCost << " " << Astar_expandedNodes << endl;
		Node * child = NULL;
		// Right Dir (0)
		if(maze->canMove(x, y, 0, current->pathCost)){
			child = Astar_tree->insert(current, x+1, y);
			child->distance = heuristic(x+1, y);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Up Dir (1)
		if(maze->canMove(x, y, 1, current->pathCost)){
			child = Astar_tree->insert(current, x, y-1);
			child->distance = heuristic(x, y-1);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Left Dir (2)
		if(maze->canMove(x, y, 2, current->pathCost)){
			child = Astar_tree->insert(current, x-1, y);
			child->distance = heuristic(x-1, y);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}

		// Down Dir (3)
		if(maze->canMove(x, y, 3, current->pathCost)){
			child = Astar_tree->insert(current, x, y+1);
			child->distance = heuristic(x, y+1);
			child->pathCost = child->parent->pathCost + 1;
			front.push(child);
		}
	}
	cout << "ayy" << endl;
	return NULL;
}


int MazeSolver::heuristic(int x, int y){

	return abs(maze->getEnd().x - x) + abs(maze->getEnd().y - y);

}

int MazeSolver::computePathCost(Node * leaf){
	Node * current = leaf;
	int pathCost = 0;
	while(current){
		pathCost++;
		current = current->parent;
	}
	return pathCost;
}

