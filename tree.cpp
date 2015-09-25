#include "tree.h"

Tree::Tree(int X, int Y)
{
	root = new Node;
	root->x=X;
	root->y=Y;
}

Tree::~Tree()
{
	if(root != NULL)
		delete_node(root);

}

void Tree::delete_node(Node * &me)
{
	if(me->left != NULL)
		delete_node(me->left);
	if(me->right != NULL)
		delete_node(me->right);
	if(me->up != NULL)
		delete_node(me->up);
	if(me->down != NULL)
		delete_node(me->down);
	delete me;
	me = NULL;
}

Node* Tree::get_root()
{
	return root;
}

Node* Tree::insert(Node * cur, int X, int Y)
{
	int cur_x = cur->x;
	int cur_y = cur->y;
	if(X < cur_x && Y == cur_y)
	{
		cur->left = new Node;
		cur->left->x = X;
		cur->left->y = Y;
		cur->left->parent = cur;
		return cur->left;
	}
	else if(X > cur_x && Y == cur_y)
	{
		cur->right = new Node;
		cur->right->x = X;
		cur->right->y = Y;
		cur->right->parent = cur;
		return cur->right;
	}
	else if(X == cur_x && Y < cur_y)
	{
		cur->up = new Node;
		cur->up->x = X;
		cur->up->y = Y;
		cur->up->parent = cur;
		return cur->up;
	}
	else if(X == cur_x && Y > cur_y)
	{
		cur->down = new Node;
		cur->down->x = X;
		cur->down->y = Y;
		cur->down->parent = cur;
		return cur->down;
	}
}
