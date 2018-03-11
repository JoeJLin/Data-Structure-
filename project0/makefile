all: Project0

Project0: main.o PriorityQueueSort.o Shopper.o PQSearch.o
	g++ -o Project0 main.o PriorityQueueSort.o Shopper.o

main.o: main.cpp PriorityQueueSort.h
	g++ -std=c++11 -c main.cpp

PriorityQueueSort.o: PriorityQueueSort.cpp PriorityQueueSort.h
	g++ -std=c++11 -c PriorityQueueSort.cpp

Shopper.o: Shopper.cpp Shopper.o
	g++ -std=c++11 -c Shopper.cpp

PQSearch.o: PQSearch.h PQSearch.cpp
	g++ -std=c++11 -c PQSearch.cpp
clean:
				rm -rf *o Project0
