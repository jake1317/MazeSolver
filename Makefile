all: main

main: tree.o maze.o main.o mazeSolver.o
	g++ tree.o maze.o main.o mazeSolver.o -g -Wall -Wextra -o mainExe

maze: maze.o mazeTester.o
	g++ maze.o mazeTester.o -g -Wall -Wextra -o mazeTest

solve: solveTester.o mazeSolver.o tree.o maze.o
	g++ solveTester.o mazeSolver.o tree.o maze.o -g -Wall -Wextra -o mazeSolve

tree.o: tree.cpp
	g++ -c -g -Wall -Wextra tree.cpp

maze.o: maze.cpp
	g++ -c -g -Wall -Wextra maze.cpp

mazeTester.o: mazeTester.cpp
	g++ -c -g -Wall -Wextr mazeTester.cpp

main.o: main.cpp
	g++ -c -g -Wall -Wextra main.cpp

solveTester.o:
	g++ -c -g -Wall -Wextra solveTester.cpp

mazeSolver.o:
	g++ -c -g -Wall -Wextra mazeSolver.cpp

clean:
	rm *.o
