CC = g++
CFLAGS = -std=c++98 -g

ofiles = main.o ArrayWrap.o ListException.o IndexException.o ConstructorException.o SizeException.o


main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main


main.o: main.cpp ArrayWrap.h ListException.h IndexException.h ConstructorException.h SizeException.h
	$(CC) $(CFLAGS) -c main.cpp

ArrayWrap.o: ArrayWrap.cpp ArrayWrap.h
	$(CC) $(CFLAGS) -c ArrayWrap.cpp

ListException.o: ListException.cpp ListException.h
	$(CC) $(CFLAGS) -c ListException.cpp

IndexException.o: IndexException.cpp IndexException.h
	$(CC) $(CFLAGS) -c IndexException.cpp	

ConstructorException.o: ConstructorException.cpp ConstructorException.h
	$(CC) $(CFLAGS) -c ConstructorException.cpp

SizeException.o: SizeException.cpp SizeException.h
	$(CC) $(CFLAGS) -c SizeException.cpp						


run: main
	valgrind ./main


clean: 
	rm -f *.o main
