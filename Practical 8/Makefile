# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g

# Define the list of object files
ofiles = main.o Node.o SinglyLinked.o List.o 

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp List.h Node.h SinglyLinked.h
	$(CC) $(CFLAGS) -c main.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

SinglyLinked.o: SinglyLinked.cpp SinglyLinked.h Node.h List.h
	$(CC) $(CFLAGS) -c SinglyLinked.cpp

List.o: List.cpp List.h Node.h
	$(CC) $(CFLAGS) -c List.cpp 

# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main
