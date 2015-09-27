#include "mazeSolver2.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("smallTurns.txt");	
	MazeSolver2 *solution = new MazeSolver2(maze); 



	Node *final = solution->Astar();	
	maze->solveMaze(final, "smallTurnsH1.txt", solution->getAstarExpandedNodes(), solution->getAstarCost());

}
