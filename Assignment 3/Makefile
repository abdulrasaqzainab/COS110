# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g -fprofile-arcs -ftest-coverage


ofiles = main.o List.o Stack.o Queue.h CLinkedList.o


main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main


main.o: main.cpp List.h Node.h Stack.h Queue.h CLinkedList.h
	$(CC) $(CFLAGS) -c main.cpp

#Node.o: Node.h
#	$(CC) $(CFLAGS) -c Node.h

List.o: List.cpp List.h Node.h
	$(CC) $(CFLAGS) -c List.cpp 

Stack.o: Stack.cpp Stack.h Node.h
	$(CC) $(CFLAGS) -c Stack.cpp

Queue.o: Queue.cpp Queue.h Node.h
	$(CC) $(CFLAGS) -c Queue.cpp


CLinkedListList.o: CLinkedListList.cpp CLinkedListListList.h Node.h List.h
	$(CC) $(CFLAGS) -c CLinkedList.cpp 

run: main
	valgrind --leak-check=full ./main

coverage:
	gcov -o . main.cpp CLinkedList.cpp List.cpp Stack.cpp Queue.cpp

clean: 
	rm -f *.o main
