using namespace std;

class Maze{
	public:
		SquareMaze(string filename);
		~SquareMaze();
	private:
		int height;
		int width;
		int *** maze;
};
