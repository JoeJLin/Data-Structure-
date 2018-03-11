prog = project2
cc = g++ -g -std=c++11
OBJS= main.o Customer.o Cart.o Line.o Register.o UMap.o Store.o

$(prog):$(OBJS)
	$(cc) -o $(prog) $(OBJS)

main.o:
	$(cc) -c main.cpp

Customer.o:
	$(cc) -c Customer.cpp

Cart.o:
	$(cc) -c Cart.cpp

Line.o:
	$(cc) -c Line.cpp

Register.o:
	$(cc) -c Register.cpp

UMap.o:
	$(cc) -c UMap.cpp

Store.o:
	$(cc) -c Store.cpp

clean:
	rm -rf *o project2
