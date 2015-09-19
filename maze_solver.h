#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include "tree.h"
#include "maze.h"



class MazeSolver
{
public:

MazeSolver(): BFS_tree(NULL), DFS_tree(NULL), A*_tree(NULL) GBFS_tree(NULL){}

~MazeSolver();

Node* BFS(Maze *cur);

Node* DFS(Maze *cur);

Node* A*(Maze *cur);

Node* GBFS(Maze *cur);

private:

Tree* BFS_tree;
Tree* DFS_tree;
Tree* A*_tree;
Tree* GBFS_tree;


};
#endif
