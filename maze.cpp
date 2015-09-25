#include "maze.h"

using namespace std;

Maze::Maze(string filename){
	// Get file vector
	vector<string> * file = readFile(filename);
	// Assign Height and Width
	height = file->size();
width = (int) (*file)[0].length() - 1;
	// Get maze array
	maze = parseMaze(file);
	delete(file);
}

Maze::~Maze(){
	for(int x = 0;x<width;x++){
		delete(maze[x]);
	}
	delete(maze);
}

vector<string> * Maze::readFile(string filename){
	ifstream mazeFile;
	mazeFile.open(filename.c_str());
	vector<string> * fileLines = new vector<string>();
	string line;
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
			if(currChar == ' ' || currChar == 'P' || currChar == '.'){
				outputMaze[x][y] = true;
			} else {
				outputMaze[x][y] = false;
			}
			// Assign start and end points
			if(currChar == '.'){
				end.x = x;
				end.y = y;
			} else if(currChar == 'P'){
				start.x = x;
				start.y = y;
			}
		}
	}
	return outputMaze;
}

void Maze::printMaze(){
	// Print start and end coordinates
	cout << "Start: (" << start.x << ", " << start.y << ")" << endl;
	cout << "End: (" << end.x << ", " << end.y << ")" << endl;
	// Iterate through Array
	for(int y = 0;y < this->height;y++){
		for(int x = 0;x < this->width;x++){
			// if coordinates are start or end,
			// Print p or .
			if(start.x == x && start.y == y){
				cout << 'P';
				continue;
			} else if(end.x == x && end.y == y){
				cout << '.';
				continue;
			}
			// Print wall and spaces
			if(maze[x][y]){
				cout << ' ';
			} else{
				cout << '%';
			}
		}
		cout << endl;
	}
}

void Maze::solveMaze(Node *leaf, string name)
{
    map<pair<int,int>,bool> mazeSolution;
    Node *cur = leaf;
    pair<int,int> curPosition;
    while(cur != NULL)
    {
        curPosition.first = cur->x;
        curPosition.second = cur->y;
        mazeSolution.insert(pair<pair<int,int>,bool>(curPosition,true));
        cur = cur->parent;
    }
    ofstream outputMaze(name.c_str());
    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {   
            if(maze[i][j] == true)
            {
                if(mazeSolution[pair<int,int>(i,j)] == true)
                    outputMaze << ".";
                else
                    outputMaze << " ";
            }
            else
                outputMaze << "%";
        }
        outputMaze << endl;
    }
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
		return false;
	}

	// Return false if out of bounds
	if(newX < 0 || newX >= this->width || newY < 0 || newY >= this->height){
		return false;
	}
	// Return array value
	return this->maze[newX][newY];
}

bool Maze::atEnd(int x, int y){
	if(x == this->end.x && y == this->end.y){
		return true;
	}
	return false;
}
