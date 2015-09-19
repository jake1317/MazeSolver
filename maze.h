using namespace std;

class Maze{
	public:
		Maze(string filename);
		~Maze();
	private:
		int height;
		int width;
		int *** maze;
};
