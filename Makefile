all: main

main: tree.o maze.o main.o mazeSolver.o
	g++ tree.o maze.o main.o mazeSolver.o -g -o mainExe

maze: maze.o mazeTester.o
	g++ maze.o mazeTester.o -g -o mazeTest

solve: solveTester.o mazeSolver.o tree.o maze.o
	g++ solveTester.o mazeSolver.o tree.o maze.o -g -o mazeSolve

tree.o: tree.cpp
	g++ -c -g tree.cpp

maze.o: maze.cpp
	g++ -c maze.cpp

mazeTester.o: mazeTester.cpp
	g++ -c mazeTester.cpp

main.o: main.cpp
	g++ -c main.cpp

solveTester.o:
	g++ -c solveTester.cpp

mazeSolver.o:
	g++ -c mazeSolver.cpp

clean:
	rm *.o
