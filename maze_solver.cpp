#include "maze_solver.h"
#include <queue>
#include <stack>
MazeSolver::~MazeSolver()
{
	delete BFS_tree;
	delete DFS_tree;
	delete A*_tree;
	delete GBFS_tree;
}

Node* MazeSolver::BFS(Maze *cur);
{
queue<Node*> frontier;
BFS_tree = new Tree(cur->getStart().x, cur->getStart().y);
frontier.push(BFS_tree.get_root());
bool **visited;
int i, j;
Node *here;
Node *next;
//initalizing the visited array
visited = new bool*[cur->getWidth()];
for(i = 0; i < cur->getWidth(); i++)
{
	visited[i] = new bool[cur->getHeight()];
	for(j=0; j< cur->getHeight(); j++)
		visited[i][j] = false;
}
visited[cur->getStart().x][cur->getStart().y] = true;

while(!frontier.empty())
{
	here = frontier.front();
	frontier.pop();
	//traveling right and checking if at solution
	if(cur->canTravel(here->x,here->y,0) && !visited[here->x+1][here->y])
	{
		next = BFS_tree.insert(here,here->x+1,here->y);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x+1][here->y] = true;
	}
	//traveling up and checking if at solution
	if(cur->canTravel(here->x,here->y,1) && !visited[here->x][here->y+1])
	{
		next = BFS_tree.insert(here,here->x,here->y+1);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x][here->y+1] = true;
	}
	//traveling left and checking if at solution
	if(cur->canTravel(here->x,here->y,2) && !visited[here->x-1][here->y])
	{
		next = BFS_tree.insert(here,here->x-1,here->y);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x-1][here->y] = true;
	}
	//traveling down and checking if at solution
	if(cur->canTravel(here->x,here->y,3) && !visited[here->x][here->y-1])
	{
		next = BFS_tree.insert(here,here->x,here->y-1);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x][here->y-1] = true;
	}
}
Node* MazeSolver::DFS(Maze *cur);
{
stack<Node*> frontier;
DFS_tree = new Tree(cur->getStart().x, cur->getStart().y);
frontier.push(BFS_tree.get_root());
bool **visited;
int i, j;
Node *here;
Node *next;
visited = new bool*[cur->getWidth()];
//initalizing the visited array
for(i = 0; i < cur->getWidth(); i++)
{
	visited[i] = new bool[cur->getHeight()];
	for(j=0; j< cur->getHeight(); j++)
		visited[i][j] = false;
}
visited[cur->getStart().x][cur->getStart().y] = true;

while(!frontier.empty())
{
	here = frontier.front();
	frontier.pop();
	//traveling right
	if(cur->canTravel(here->x,here->y,0) && !visited[here->x+1][here->y])
	{
		next = DFS_tree.insert(here,here->x+1,here->y);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x+1][here->y] = true;
	}
	//traveling up 
	if(cur->canTravel(here->x,here->y,1) && !visited[here->x][here->y+1])
	{
		next = DFS_tree.insert(here,here->x,here->y+1);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x][here->y+1] = true;
	}
	//traveling left
	if(cur->canTravel(here->x,here->y,2) && !visited[here->x-1][here->y])
	{
		next = DFS_tree.insert(here,here->x-1,here->y);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x-1][here->y] = true;
	}
	//traveling down
	if(cur->canTravel(here->x,here->y,3) && !visited[here->x][here->y-1])
	{
		next = DFS_tree.insert(here,here->x,here->y-1);
		if(next->x == cur->getEnd().x && next->y == cur->getEnd().y)
			return next;
		frontier.push(next);
		visited[here->x][here->y-1] = true;
	}
	return DFS_tree.getroot();
}
}
