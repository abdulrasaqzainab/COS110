CC = g++
CFLAGS = -std=c++98 -g

ofiles = main.o node.o 


main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main


main.o: main.cpp node.h 
	$(CC) $(CFLAGS) -c main.cpp

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp


run: main
	valgrind ./main


clean: 
	rm -f *.o main
