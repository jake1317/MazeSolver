#include "mazeSolver2.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("mediumMaze.txt");	
	MazeSolver *solution = new MazeSolver(maze); 



	Node *final = solution->Astar();	

	delete maze;
}
