all: main

main: tree.o maze.o main.o
	g++ tree.o maze.o main.o -o mainExe

maze: maze.o mazeTester.o
	g++ maze.o mazeTester.o -o mazeTest

solve: solveTester.o mazeSolver.o tree.o maze.o
	g++ solveTester.o mazeSolver.o tree.o maze.o -o mazeSolve

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

mazeSolve.o:
	g++ -c mazeSolve.cpp

clean:
	rm *.o
