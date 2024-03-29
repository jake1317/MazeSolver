#include "maze.h"

using namespace std;

Maze::Maze(string filename){
	// Get file vector
	vector<string> * file = readFile(filename);
	// Assign Height and Width
	height = file->size();
	width = (int) (*file)[0].length();
	ghost.x = ghost.y = leftGhostWall = rightGhostWall = -1;
	// Get maze array
	maze = parseMaze(file);
	if(ghost.x > -1)
		discoverGhost();
	delete(file);
}

Maze::~Maze(){
	for(int x = 0;x<width;x++){
		delete(maze[x]);
	}
	delete(maze);
}

vector<string> * Maze::readFile(string filename){
	// open file, initialize variables
	ifstream mazeFile;
	mazeFile.open(filename.c_str());
	vector<string> * fileLines = new vector<string>();
	string line;

	// Iterate through file, add to vector
	while(mazeFile.is_open() && getline(mazeFile, line)){
		fileLines->push_back(line);
	}
	mazeFile.close();
	return fileLines;
}

bool ** Maze::parseMaze(vector<string> * maze){
	bool ** outputMaze = new bool*[this->width];
	// Iterate on x
	for(int x = 0;x < this->width; x++){
		outputMaze[x] = new bool[this->height];
		// Iterate on y
		for(int y = 0;y < this->height; y++){
			// Get important chars
			char currChar = (*maze)[y].at(x);
			// Assign boolean
			if(currChar == '%'){
				outputMaze[x][y] = false;
			} else {
				outputMaze[x][y] = true;
			}
			// Assign start and end points
			if(currChar == '.'){
				end.x = x;
				end.y = y;
			} else if(currChar == 'P'){
				start.x = x;
				start.y = y;
			} else if(currChar == 'G'){
				ghost.x = x;
				ghost.y = y;
			}
		}
	}
	return outputMaze;
}

void Maze::solveMaze(Node *leaf, string name, int nodes, int path)
{
    map<pair<int,int>,int> mazeSolution;
    Node *cur = leaf;
    pair<int,int> curPosition;
    while(cur != NULL)
    {
        curPosition.first = cur->x;
        curPosition.second = cur->y;
		mazeSolution[curPosition]++;
        //mazeSolution.insert(pair<pair<int,int>,int>(curPosition,1));
        cur = cur->parent;
    }
    ofstream outputMaze(name.c_str());
    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {   
            if(maze[i][j] == true)
            {
				if(i == start.x && j == start.y)
				    outputMaze << "P";
                else if(mazeSolution[pair<int,int>(i,j)] == 1)
                    outputMaze << ".";
				else if(mazeSolution[pair<int,int>(i,j)] > 1)
					outputMaze << mazeSolution[pair<int,int>(i,j)];
                else
                    outputMaze << " ";
            }
            else
                outputMaze << "%";
        }
        outputMaze << endl;
    }
    outputMaze << "Nodes expanded: " << nodes << " Total Path Length: " << path << endl;
    outputMaze.close();
}

bool Maze::canMove(int x, int y, int dir){
	int newX, newY;
	// Parse Maze
	if(dir == 0){
		newX = x + 1;
		newY = y;
	} else if(dir == 1){
		newX = x;
		newY = y - 1;
	} else if(dir == 2){
		newX = x - 1;
		newY = y;
	} else if(dir == 3){
		newX = x;
		newY = y + 1;
	} else {
		return maze[x][y];
	}

	// Return false if out of bounds
	if(newX < 0 || newX >= this->width || newY < 0 || newY >= this->height){
		return false;
	}
	// Return array value
	return this->maze[newX][newY];
}

bool Maze::canMove(int x, int y, int dir, int n){
	bool canM = canMove(x,y,dir);

	if(dir == 0)
		x++; 
	if(dir == 1)
		y--;
	if(dir == 2)
		x--;
	if(dir == 3)
		y++;

	coordinate ghostPos = getGhostPos(n+1);
	return canM && (x != ghostPos.x || y != ghostPos.y);
}

bool Maze::atEnd(int x, int y){
	if(x == this->end.x && y == this->end.y){
		return true;
	}
	return false;
}

int Maze::zigZag(int width, int initOffset, int n){
	n += initOffset;
	int out = n%(width*2);
	if(out > width){
		out = (width*2) - out;
	}
	return out;
}

void Maze::discoverGhost(){
	int decX = ghost.x;
	while(maze[decX][ghost.y]){
		decX--;
	}
	leftGhostWall = decX + 1;
	int incX  = ghost.x;
	while(maze[incX][ghost.y]){
		incX++;
	}
	rightGhostWall = incX - 1;
}

Maze::coordinate Maze::getGhostPos(int n){
	if(ghost.x == -1 && ghost.y == -1){
		return ghost;
	}
	int offset = ghost.x - leftGhostWall;
	int width = rightGhostWall - leftGhostWall;
	struct coordinate out;
	out.y = ghost.y;
	out.x = zigZag(width, offset, n) + leftGhostWall;
	return out;
}
