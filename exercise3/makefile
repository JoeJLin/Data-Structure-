all: exercise3

exercise3: main.o SLList.o
	g++ -o exercise3 main.o SLList.o
main.o:
	g++ -std=c++11 -c main.cpp

SLList.o: SLList.h
	g++ -std=c++11 -c SLList.cpp

clean:
		rm -rf *o exercise3
