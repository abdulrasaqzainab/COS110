#include "List.h"
#include "Node.h"
#include "SinglyLinked.h"

#include "List.cpp"
#include "Node.cpp"
#include "SinglyLinked.cpp"

#include <iostream>
#include <string>

using namespace std;

void test1()
{
int arr[] = {5, 2, 8, 1,11, 9};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    SinglyList<int> myList(arr, arrSize);

    myList.insert(7, 2);
    
    myList.remove(2);
   
    int index1 = 3;
    Node<int>* node1 = myList[index1];
    if (node1) {
        std::cout << "Element at the index " << index1 << "is " << node1->getData() << std::endl;
    } else {
        std::cout << "This index " << index1 << " is out of bounds." << std::endl;
    }

   
    int searchData = 8;
    Node<int>* node2 = myList(&searchData);
    if (node2) {
        std::cout << "Found this " << searchData << " at index: " << myList.getIndexFromFront(searchData) << std::endl;
    } else {
        std::cout << searchData << "is not in my list" << std::endl;
    }

   
    List<int>* sortedListAsc = myList.sort(true);
    
    delete sortedListAsc;

    List<int>* sortedListDesc = myList.sort(false);
    
    delete sortedListDesc;

   
    Node<int>* smallest = myList.findSmallest();
    Node<int>* biggest = myList.findBiggest();

    if (smallest) {
        std::cout << "Smallest: " << smallest->getData() << std::endl;
    }

    if (biggest) {
        std::cout << "Biggest: " << biggest->getData() << std::endl;
    }


    List<int>* clonedList = myList.clone();
   
    delete clonedList;

}


void test2()
{
SinglyList<int> myList;

    
    myList.insert(42, myList.size());
    myList.insert(17, myList.size());
    myList.insert(33, myList.size());
    myList.insert(10, myList.size());
    myList.insert(5, myList.size());

    
    std::cout << "Original: ";
   
    List<int>* sortedListAsc = myList.sort(true);

    
    std::cout << "Sort in ascending ";//<< not workin
    std::cout << sortedListAsc << std::endl;

   
    List<int>* sortedListDesc = myList.sort(false);

    
    std::cout << "Sorted in descending: ";
    std::cout << sortedListDesc << std::endl;

    
    delete sortedListAsc;
    delete sortedListDesc;
}


int main(int argc, char const *argv[])
{
 
 test1();
 
test2();
    return 0;
}
