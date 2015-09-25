#include "mazeSolver.h"
#include "tree.h"
#include <iostream>
using namespace std;

int main(){
	Maze *maze = new Maze("bigMaze.txt");
    MazeSolver *solution = new MazeSolver(maze);
    Node *final = solution->GBFS();
  //  maze->solveMaze(final, "bigMazeBFS.txt");
}
