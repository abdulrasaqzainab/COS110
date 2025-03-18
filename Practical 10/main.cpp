#include "ArrayWrap.h"
#include "ListException.h"
#include "ConstructorException.h"
#include "IndexException.h"
#include "SizeException.h"
#include <iostream>
#include <string>


void t1()
{
    IndexException indexException(3, 10);
try {
    throw indexException;
} catch (ListException& e) {
    std::cout << e.getError() << std::endl; 
}


ConstructorException constructorException;
try {
    throw constructorException;
} catch (ListException& e) {
    std::cout << e.getError() << std::endl; 
}


SizeException sizeException(0);
try {
    throw sizeException;
} catch (ListException& e) {
    std::cout << e.getError() << std::endl;
}

SizeException sizeException2(5);
try {
    throw sizeException2;
} catch (ListException& e) {
    std::cout << e.getError() << std::endl;  
}



   
ArrayWrap<int> arr(5);


arr.push_back(19);
arr.push_back(2);
arr.push_back(7);
arr.print(); 

int popped = arr.pop_back(); 


int value = arr[1]; 

arr.swap(0, 1); 
arr.remove(1); 
arr.clear();

arr.print(); 


try {
    arr[5];  
} catch (IndexException &e) {
    std::cout << e.getError() << std::endl;
}

try {
    arr.swap(3, 1);  
} catch (IndexException& e) {
    std::cout << e.getError() << std::endl;
}

try {
    arr.push_back(42); 
} catch (SizeException& e) {
    std::cout << e.getError() << std::endl;
}




}

void t2()
{

}

int main()
{

    t1();
    std::cout<<"\n";

    t2();

    

    return 0;
}