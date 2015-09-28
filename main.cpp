#include "mazeSolver2.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){

	Maze *maze = new Maze("smallGhost.txt");	
	MazeSolver *solution = new MazeSolver(maze); 

	Node * final = solution->AstarNoVisit();
	maze->solveMaze(final, "smallGhostAstar.txt", solution->getAstarExpandedNodes(), solution->getAstarCost());
/*
	maze = new Maze("mediumGhost.txt");	
	solution = new MazeSolver(maze); 

	final = solution->Astar();
	maze->solveMaze(final, "mediumGhostAstar.txt", solution->getAstarExpandedNodes(), solution->getAstarCost());

	maze = new Maze("bigGhost.txt");	
	solution = new MazeSolver(maze); 

	final = solution->Astar();
	maze->solveMaze(final, "bigGhostAstar.txt", solution->getAstarExpandedNodes(), solution->getAstarCost());
	Node * final = solution->BFS();
	maze->solveMaze(final, "openMazeBFS.txt",solution->getBFSExpandedNodes(), solution->getBFSCost());

	final = solution->DFS();
	maze->solveMaze(final, "openMazeDFS.txt",solution->getDFSExpandedNodes(), solution->getDFSCost());

	final = solution->GBFS();
	maze->solveMaze(final, "openMazeGBFS.txt",solution->getGBFSExpandedNodes(), solution->getGBFSCost());

	cout << "Open Done" << endl;

	final = solution->Astar();
	maze->solveMaze(final, "openMazeAstar.txt",solution->getAstarExpandedNodes(), solution->getAstarCost());
	

//	delete maze;
//	delete solution;
	
	maze = new Maze("mediumMaze.txt");	
	solution = new MazeSolver(maze); 

	final = solution->BFS();
	maze->solveMaze(final, "mediumMazeBFS.txt",solution->getBFSExpandedNodes(), solution->getBFSCost());

	final = solution->DFS();
	maze->solveMaze(final, "mediumMazeDFS.txt",solution->getDFSExpandedNodes(), solution->getDFSCost());

	final = solution->GBFS();
	maze->solveMaze(final, "mediumMazeGBFS.txt",solution->getGBFSExpandedNodes(), solution->getGBFSCost());

	final = solution->Astar();
	maze->solveMaze(final, "mediumMazeAstar.txt",solution->getAstarExpandedNodes(), solution->getAstarCost());

//	delete maze;
//	delete solution;

	maze = new Maze("bigMaze.txt");	
	solution = new MazeSolver(maze); 

	final = solution->BFS();
	maze->solveMaze(final, "bigMazeBFS.txt",solution->getBFSExpandedNodes(), solution->getBFSCost());

	final = solution->DFS();
	maze->solveMaze(final, "bigMazeDFS.txt",solution->getDFSExpandedNodes(), solution->getDFSCost());

	final = solution->GBFS();
	maze->solveMaze(final, "bigMazeGBFS.txt",solution->getGBFSExpandedNodes(), solution->getGBFSCost());

	final = solution->Astar();
	maze->solveMaze(final, "bigMazeAstar.txt",solution->getAstarExpandedNodes(), solution->getAstarCost());

//	delete maze;
//	delete solution;
*/
}
