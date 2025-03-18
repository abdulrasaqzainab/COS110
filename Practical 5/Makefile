# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g

# Define the list of object files
ofiles = main.o Brute.o Mage.o Ninja.o ShadowBone.o Soldier.o Sword.o 

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp Brute.h Mage.h Ninja.h ShadowBone.h Soldier.h Sword.h 
	$(CC) $(CFLAGS) -c main.cpp

Brute.o: Brute.cpp Brute.h
	$(CC) $(CFLAGS) -c Brute.cpp

Mage.o: Mage.cpp Mage.h
	$(CC) $(CFLAGS) -c Mage.cpp

Ninja.o: Ninja.cpp Ninja.h
	$(CC) $(CFLAGS) -c Ninja.cpp

ShadowBone.o: ShadowBone.cpp ShadowBone.h
	$(CC) $(CFLAGS) -c ShadowBone.cpp

Sword.o: Sword.cpp Sword.h
	$(CC) $(CFLAGS) -c Sword.cpp	

# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main
