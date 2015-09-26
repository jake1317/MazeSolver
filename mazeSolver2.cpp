int MazeSolver2::computePathCost(Node * leaf){
	Node * current = leaf;
	Node * par = current->parent;
	Node * parpar = par->parent;
	int dir, newdir, pathCost = 0;
	
	while(current){
		dir = facing(par, parpar);
		newdir = facing(current, par);
			
		if(dir == newdir)
			pathCost++;
		else 
			pathCost+=2;
		current = current->parent;
		if(par != NULL)
			par = par->parent;
		if(parpar != NULL)
			parpar = parpar->parent;
	}
	return pathCost;
}

int MazeSolver2::facing(Node *current, Node *par)
{
	int newdir;
	if(par == NULL)
		newdir = 0;
	if(par->y == current->y && (par->x+1)==current->x)
		newdir=2
	else if(par->y == current->y && dir (par->x-1)==current->x)
		newdir=0
	else if((par->y+1) == current->y && (par->x)==current->x)
		newdir=1
	else
		newdir=3
	return newdir;
}


