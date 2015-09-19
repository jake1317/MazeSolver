#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

using namespace std;

class Tree
{
public:

Tree(): root(NULL){}

Tree(int X, int Y);

~Tree();

void insert(Node *cur, int X, int Y);

private:
Node *root;

void delete_node(Node * &me);
};
#endif
