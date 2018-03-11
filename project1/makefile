prog = project1
cc = g++ -g -std=c++11
OBJS= main.o LispList.o

$(prog):$(OBJS)
	$(cc) -o $(prog) $(OBJS)

main.o:
	$(cc) -c main.cpp

Lisplist.o:
	$(cc) -c Lisplist.cpp

clean:
	rm -rf *o project1
