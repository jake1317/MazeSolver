#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


//this tree class has four childeren and a parent pointer for easy traversal up
class Tree
{
public:

	Tree(): root(NULL){}

	Tree(int X, int Y);

	~Tree();

	Node* insert(Node *cur, int X, int Y);

	Node* get_root();

private:

	Node *root;

	void delete_node(Node * &me);
};
#endif
