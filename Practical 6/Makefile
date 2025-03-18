# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++98 -g

# Define the list of object files
ofiles = main.o bulk.o discountedProduct.o item.o labor.o product.o service.o shop.o subscription.o

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp bulk.o discountedProduct.cpp item.cpp labor.cpp product.cpp service.cpp shop.cpp subscription.cpp
	$(CC) $(CFLAGS) -c main.cpp

bulk.o: bulk.cpp bulk.h
	$(CC) $(CFLAGS) -c bulk.cpp

discountedProduct.o: discountedProduct.cpp discountedProduct.h
	$(CC) $(CFLAGS) -c discountedProduct.cpp	

item.o: item.cpp item.h
	$(CC) $(CFLAGS) -c item.cpp

labor.o: labor.cpp labor.h
	$(CC) $(CFLAGS) -c labor.cpp

product.o: product.cpp product.h
	$(CC) $(CFLAGS) -c product.cpp

service.o: service.cpp service.h
	$(CC) $(CFLAGS) -c service.cpp

shop.o: shop.cpp shop.h
	$(CC) $(CFLAGS) -c shop.cpp	

subscription.o: subscription.cpp subscription.h
	$(CC) $(CFLAGS) -c subscription.cpp				
# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main
