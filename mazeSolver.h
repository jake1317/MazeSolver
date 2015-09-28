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
		
	Node* Astar();

	Node* AstarNoRSD();

	// accessors
	int getBFSExpandedNodes(){ return BFS_expandedNodes; }
	int getDFSExpandedNodes(){ return DFS_expandedNodes; }
	int getGBFSExpandedNodes(){ return GBFS_expandedNodes; }
	int getAstarExpandedNodes(){ return Astar_expandedNodes; }
	int getAstarNoRSDExpandedNodes(){ return AstarNoRSD_expandedNodes; }

	int getBFSCost(){ return BFS_cost; }
	int getDFSCost(){ return DFS_cost; }
	int getGBFSCost(){ return GBFS_cost; }
	int getAstarCost(){ return Astar_cost; }
	int getAstarNoRSDCost(){ return AstarNoRSD_cost; }

	// Dereferencing Comparison Struct
	struct indirect_compare
	{
		template <typename T>
		bool operator()(const T& first, const T& second) const 
		{
			return *first < *second;
		}
	};
protected:
	Maze * maze;

	// Search Trees
	Tree* BFS_tree;
	Tree* DFS_tree;
	Tree* GBFS_tree;
	Tree* Astar_tree;
	Tree* AstarNoRSD_tree;

	// Expanded nodes and cost variables
	int BFS_expandedNodes;
	int DFS_expandedNodes;
	int GBFS_expandedNodes;
	int Astar_expandedNodes;
	int AstarNoRSD_expandedNodes;
	int BFS_cost;
	int DFS_cost;
	int GBFS_cost;
	int Astar_cost;
	int AstarNoRSD_cost;

private:
	int heuristic(int x, int y);
	int computePathCost(Node *leaf);
};
#endif
