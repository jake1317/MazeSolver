#ifndef BTREE_H
#define BTREE_H

class btree
{
public:

btree(): rool(NULL){}


void insert(node *cur, int X, int Y);

node *search(int X, int Y);


private:

struct node
{
int x;
int y;
node *left;
node *right;
node *parent;
};
node *root

}
