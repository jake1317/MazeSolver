all: main

main: btree.o maze.o main.o
	g++ btree.o maze.o main.o -o mazeSolve

btree.o: btree.cpp
	g++ -c btree.cpp

maze.o: maze.cpp
	g++ -c maze.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
