# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g

# Define the list of object files
ofiles = main.o MyString.o

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp MyString.h
	$(CC) $(CFLAGS) -c main.cpp

MyString.o: MyString.h MyString.cpp
	$(CC) $(CFLAGS) -c MyString.cpp

# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main
