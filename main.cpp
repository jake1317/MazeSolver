#include "tree.h"
#include "maze.h"
#include <iostream>
using namespace std;

int main(){
	Tree *test = new Tree(1,1);
	Node *tright = test->insert(test->get_root(),2,1);
	cout << tright->x <<endl;
	
}
