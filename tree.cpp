#include "tree.h"

Tree::Tree(int X, int Y)
{
	root = new Node();
	root->x=X;
	root->y=Y;
	root->parent = NULL;
	root->right = NULL;
	root->left = NULL;
	root->up = NULL;
	root->down = NULL;
}

Tree::~Tree()
{
	if(root != NULL)
		delete_node(root);

}

void Tree::delete_node(Node * &me)
{
	Node *nodel = me->left;	
	Node *noder = me->right;
	Node *nodeu = me->up;
	Node *noded = me->down;
	delete me;
	me = NULL;
	if(nodel != NULL)
		delete_node(nodel);
	if(noder != NULL)
		delete_node(noder);
	if(nodeu != NULL)
		delete_node(nodeu);
	if(noded != NULL)
		delete_node(noded);
}

Node* Tree::get_root()
{
	return root;
}

Node* Tree::insert(Node * cur, int X, int Y)
{
	int cur_x = cur->x;
	int cur_y = cur->y;
	if((X == cur_x - 1) && Y == cur_y)
	{
		cur->left = new Node;
		cur->left->x = X;
		cur->left->y = Y;
		cur->left->parent = cur;
		cur->left->right = cur;
		cur->left->left = NULL;
		cur->left->up = NULL;
		cur->left->down = NULL;
		return cur->left;
	}
	else if((X == cur_x+1) && Y == cur_y)
	{
		cur->right = new Node;
		cur->right->x = X;
		cur->right->y = Y;
		cur->right->parent = cur;
		cur->right->right = NULL;
		cur->right->left = cur;
		cur->right->up = NULL;
		cur->right->down = NULL;
		return cur->right;
	}
	else if(X == cur_x && (Y+1) == (cur_y))
	{
		cur->up = new Node;
		cur->up->x = X;
		cur->up->y = Y;
		cur->up->parent = cur;
		cur->up->right = NULL;
		cur->up->left = NULL;
		cur->up->up = NULL;
		cur->up->down = cur;
		return cur->up;
	}
	else if(X == cur_x && (Y -1)== cur_y)
	{
		cur->down = new Node;
		cur->down->x = X;
		cur->down->y = Y;
		cur->down->parent = cur;
		cur->down->right = NULL;
		cur->down->left = NULL;
		cur->down->up = cur;
		cur->down->down = NULL;
		return cur->down;
	}
	return cur;
}
