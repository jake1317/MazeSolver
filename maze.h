#include <fstream>
#include <vector>

using namespace std;

class Maze{
	public:
		Maze(string filename);
		~Maze();
	private:
		vector<string> * readFile(string filename);
		int *** parseMaze(vector<string> * maze);
		int height;
		int width;
		int *** maze;
};
