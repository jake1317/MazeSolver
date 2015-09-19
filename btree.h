#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Btree
{
public:

Btree(): root(NULL){}

Btree(int X, int Y);

~Btree();

void insert(node *cur, int X, int Y);

node *search(int X, int Y);


private:

struct Node
{
int x;
int y;
Node *left;
Node *right;
Node *parent;
};
Node *root

}
