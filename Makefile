all: main

main: tree.o maze.o main.o
	g++ tree.o maze.o main.o -o mazeSolve

maze: maze.o mazeTester.o
	g++ maze.o mazeTester.o -o mazeTest

tree.o: tree.cpp
	g++ -c tree.cpp

maze.o: maze.cpp
	g++ -c maze.cpp

mazeTester.o: mazeTester.cpp
	g++ -c mazeTester.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
