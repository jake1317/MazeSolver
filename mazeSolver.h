#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "maze.h"
#include "tree.h"

class MazeSolver
{
public:
	
    MazeSolver(Maze *newMaze);
	
	~MazeSolver();
	
	Node* BFS();
	
	Node* DFS();
	
	Node* GBFS();
		
//	Node* Astar();

	// Comparison Struct
	struct indirect_compare
	{
		template <typename T>
		bool operator()(const T& first, const T& second) const 
		{
			return *first < *second;
		}
	};

private:

	Maze * maze;

	Tree* BFS_tree;
	Tree* DFS_tree;
	Tree* Astar_tree;
	Tree* GBFS_tree;

	int BFS_expandedNodes;
	int DFS_expandedNodes;
	int Astar_expandedNodes;
	int GBFS_expandedNodes;
	int BFS_cost;
	int DFS_cost;
	int Astar_cost;
	int GBFS_cost;

	int heuristic(int x, int y);
	int computePathCost(Node *leaf);
};
#endif
