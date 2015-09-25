#ifndef NODE_H
#define NODE_H

struct Node
{
	int x;
	int y;
	int distance;
	Node *left;
	Node *right;
	Node *up;
	Node *down;
	Node *parent;
	bool operator<(const Node& a){
		return this->distance > a.distance;
	}
};
#endif
