#include <fstream>
#include <vector>

using namespace std;

class Maze{
	struct coordinate{
		int x;
		int y;
	};
	public:
		// Constructors n stuff
		Maze(string filename);
		~Maze();

		// Misc Functions
		void printMaze();

		// Accessors
		int getHeight(){ return height; };
		int getWidth(){ return width; };
		coordinate getStart(){ return start; };
		coordinate getEnd(){ return end; };
	private:
		vector<string> * readFile(string filename);
		bool ** parseMaze(vector<string> * maze);
		int height;
		int width;
		coordinate start;
		coordinate end;
		bool ** maze;
};
