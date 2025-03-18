# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g

# Define the list of object files
ofiles = main.o Dictionary.o ScoreBoard.o Tuple.o 

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp Dictionary.h ScoreBoard.h Tuple.h
	$(CC) $(CFLAGS) -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	$(CC) $(CFLAGS) -c Dictionary.cpp

ScoreBoard.o: ScoreBoard.cpp ScoreBoard.h Dictionary.h Tuple.h
	$(CC) $(CFLAGS) -c ScoreBoard.cpp

Tuple.o: Tuple.cpp Tuple.h
	$(CC) $(CFLAGS) -c Tuple.cpp

# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main
