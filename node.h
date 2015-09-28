#ifndef NODE_H
#define NODE_H
//this is the struct for a node in the tree
struct Node
{
	int x;
	int y;
	int distance;
	int pathCost;
	Node *left;
	Node *right;
	Node *up;
	Node *down;
	Node *parent;
	//this is a comparison operator
	bool operator<(const Node& a){
		return (this->pathCost + this->distance) > (a.pathCost + a.distance);
	}
};
#endif
