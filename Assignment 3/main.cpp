#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"


using namespace std;


/* -------------------------------------------------------------------------- */
/*                                 PLEASE READ                                */
/* -------------------------------------------------------------------------- */
/*
    Hello 110 Student :). This main.cpp provides very very basic testing that should help prevent some errors
    in your code. However, it is not a complete test suite. You should write your own tests to ensure that your
    code is working as expected

    Please do not be surprised if this main works but your FF upload fails as the FF main is different from this one.
    This Assignment has many edge cases, please test as much as possible.
*/



void t1(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.print();
    list.remove(0);
    list.print();
    list.remove(100);//test for invalid
    list.print();
    list.remove(1);
    list.print();
    list.removeElements(2);//!!!!
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n
}

void tdouble()
{
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<double> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.print();
    list.remove(0);
    list.print();
    list.remove(100);//test for invalid
    list.print();
    list.remove(1);
    list.print();
    list.removeElements(2);//!!!!
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n

     cout<<"Testing CLinkedList"<<endl;
    //CLinkedList<double> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<double> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    

     std::cout<<"My funky testsing\n";
    CLinkedList<double> myList;

    // Test prepend, append, and print
    myList.prepend(1);
    myList.prepend(0);
    myList.append(2);
    myList.append(3);
    std::cout<<"Print after prepend and append\n";
    myList.print(); 

    // Test insert
    myList.insert(1, 1);
    std::cout<<"Print after inserting at index 1\n";
    myList.print();  

    // Test remove
    myList.remove(2);
    std::cout<<"Print after removing node at index 2\n";
    myList.print();
    //myList.print(); 
    
    // Test removeElements
    myList.removeElements(2);
    std::cout<<"Print after removing node with 2 as data\n";
    myList.print();  
    // Test reverse
    myList.reverse();
    std::cout<<"Print reverse\n";
    myList.print();  
    // Test clear
    myList.clear();
    std::cout<<"Print clear\n";
    myList.print(); 
    ///PART ONE OF FUNCKY 

    // Test length
    std::cout << "Length: " << myList.length() << std::endl;  

    // Create another linked list
    CLinkedList<double> otherList;
    otherList.append(5);
    otherList.append(4);
    
std::cout<<"Testing +=\n";
    // Test += operator
    otherList.clear();
    otherList.append(11);
    otherList.append(6);

    otherList.append(23);
    otherList.append(76);
    myList.prepend(1);
    myList.prepend(0);
    myList.append(2);
    myList.append(3);
   myList += otherList;
    myList.print();  

    // Test == operator
    std::cout << "Lists are equal: " << (myList == otherList) << std::endl;  

    // Test -= operator
    CLinkedList<double> *diffList = myList - otherList;
    diffList->print();  
    // Test removeDuplicates
    myList.append(5);
    myList.append(5);
    myList.removeDuplicates();
    
    std::cout<<"Testing remove duplicates\n";
    myList.print();  
    // Test consume
    
    std::cout<<"Testing consume\n";
    myList.consume(otherList);
    myList.print(); 

    myList.filter(">",4);//segg
    myList.filter("<",4);
    myList.filter("==",4);
    myList.filter("+",4);
    myList.filter("-",4);
   myList.print(); 
   std::cout<<"Checking slice\n";
   myList.slice(2,4);
    myList.print(); 
}

void tfloat()
{
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<float> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.print();
    list.remove(0);
    list.print();
    list.remove(100);//test for invalid
    list.print();
    list.remove(1);
    list.print();
    list.removeElements(2);//!!!!
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n

     cout<<"Testing CLinkedList"<<endl;
   // CLinkedList<float> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<float> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    

     std::cout<<"My funky testsing\n";
    CLinkedList<float> myList;

    // Test prepend, append, and print
    myList.prepend(1);
    myList.prepend(0);
    myList.append(2);
    myList.append(3);
    std::cout<<"Print after prepend and append\n";
    myList.print(); 

    // Test insert
    myList.insert(1, 1);
    std::cout<<"Print after inserting at index 1\n";
    myList.print();  

    // Test remove
    myList.remove(2);
    std::cout<<"Print after removing node at index 2\n";
    myList.print();
    //myList.print(); 
    
    // Test removeElements
    myList.removeElements(2);
    std::cout<<"Print after removing node with 2 as data\n";
    myList.print();  
    // Test reverse
    myList.reverse();
    std::cout<<"Print reverse\n";
    myList.print();  
    // Test clear
    myList.clear();
    std::cout<<"Print clear\n";
    myList.print(); 
    ///PART ONE OF FUNCKY 

    // Test length
    std::cout << "Length: " << myList.length() << std::endl;  

    // Create another linked list
    CLinkedList<float> otherList;
    otherList.append(4);
    otherList.append(5);

    // Test += operator
   myList += otherList;
    myList.print();  

    // Test == operator
    std::cout << "Lists are equal: " << (myList == otherList) << std::endl;  

    // Test -= operator
    CLinkedList<float> *diffList = myList - otherList;
    diffList->print();  
    // Test removeDuplicates
    myList.append(4);
    myList.append(5);
    myList.removeDuplicates();
    
    std::cout<<"Testing remove duplicates\n";
    myList.print();  
    // Test consume
    
    std::cout<<"Testing consume\n";
    myList.consume(otherList);
    myList.print(); 

myList.filter(">",4);//segg
    myList.filter("<",4);
    myList.filter("==",4);
    myList.filter("+",4);
    myList.filter("-",4);
   // myList.filter(">",4);//segg
   //myList.print(); 
   std::cout<<"Checking slice\n";
   myList.slice(2,4);
    myList.print(); 
}

void tshort()
{
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<short> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.print();
    list.remove(0);
    list.print();
    list.remove(100);//test for invalid
    list.print();
    list.remove(1);
    list.print();
    list.removeElements(2);//!!!!
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n

     cout<<"Testing CLinkedList"<<endl;
   // CLinkedList<short> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<short> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    

     std::cout<<"My funky testsing\n";
    CLinkedList<short> myList;

    // Test prepend, append, and print
    myList.prepend(1);
    myList.prepend(0);
    myList.append(2);
    myList.append(3);
    std::cout<<"Print after prepend and append\n";
    myList.print(); 

    // Test insert
    myList.insert(1, 1);
    std::cout<<"Print after inserting at index 1\n";
    myList.print();  

    // Test remove
    myList.remove(2);
    std::cout<<"Print after removing node at index 2\n";
    myList.print();
    //myList.print(); 
    
    // Test removeElements
    myList.removeElements(2);
    std::cout<<"Print after removing node with 2 as data\n";
    myList.print();  
    // Test reverse
    myList.reverse();
    std::cout<<"Print reverse\n";
    myList.print();  
    // Test clear
    myList.clear();
    std::cout<<"Print clear\n";
    myList.print(); 
    ///PART ONE OF FUNCKY 

    // Test length
    std::cout << "Length: " << myList.length() << std::endl;  

    // Create another linked list
    CLinkedList<short> otherList;
    otherList.append(4);
    otherList.append(5);

    // Test += operator
   myList += otherList;
    myList.print();  

    // Test == operator
    std::cout << "Lists are equal: " << (myList == otherList) << std::endl;  

    // Test -= operator
    CLinkedList<short> *diffList = myList - otherList;
    diffList->print();  
    // Test removeDuplicates
    myList.append(4);
    myList.append(5);
    myList.removeDuplicates();
    
    std::cout<<"Testing remove duplicates\n";
    myList.print();  
    // Test consume
    
    std::cout<<"Testing consume\n";
    myList.consume(otherList);
    myList.print(); 

   // myList.filter(">",4);//segg
   //myList.print(); 
   myList.filter(">",4);//segg
    myList.filter("<",4);
    myList.filter("==",4);
    myList.filter("+",4);
    myList.filter("-",4);
   std::cout<<"Checking slice\n";
   myList.slice(2,4);
    myList.print(); 
}



void t2(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<int> list2;
    list2 = list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
}

void t3(){
    cout<<"Testing Stack"<<endl;
    Stack<int> stack;
    cout<<"Testing basics"<<endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<stack.pop()<<endl;// Output should be "4\n"
    cout<<stack.peek()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"Testing copy constructor"<<endl;
    Stack<int> stack2(stack);
    cout<<stack2.pop()<<endl;// Output should be "3\n"
    cout<<stack2.pop()<<endl;// Output should be "2\n"
    cout<<stack2.pop()<<endl;// Output should be "1\n"
    cout<<stack2.pop()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout<<"MY TESTS\n";
    Stack<int> qz;
    std::cout<<" Is qz empty?";
    std::cout<<qz.isEmpty()<<std::endl;

    
}

void t4(){
    cout<<"Testing Queue"<<endl;
    Queue<int> queue;
    cout<<"Testing basics"<<endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.peek()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "4\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"Testing copy constructor"<<endl;
    Queue<int> queue2(queue);
    cout<<queue2.dequeue()<<endl;// Output should be "1\n"
    cout<<queue2.dequeue()<<endl;// Output should be "2\n"
    cout<<queue2.dequeue()<<endl;// Output should be "3\n"
    cout<<queue2.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout<<"MY TESTS\n";
    Queue<int> qz;
    std::cout<<" Is qz empty?";
    std::cout<<qz.isEmpty()<<std::endl;





}

void tmine()
{

    std::cout<<"My funky testsing\n";
    CLinkedList<int> myList;

    // Test prepend, append, and print
    myList.prepend(1);
    myList.prepend(0);
    myList.append(2);
    myList.append(3);
    std::cout<<"Print after prepend and append\n";
    myList.print(); 

    // Test insert
    myList.insert(1, 1);
    std::cout<<"Print after inserting at index 1\n";
    myList.print();  

    // Test remove
    myList.remove(2);
    std::cout<<"Print after removing node at index 2\n";
    myList.print();
    //myList.print(); 
    
    // Test removeElements
    myList.removeElements(2);
    std::cout<<"Print after removing node with 2 as data\n";
    myList.print();  
    // Test reverse
    myList.reverse();
    std::cout<<"Print reverse\n";
    myList.print();  
    // Test clear
    myList.clear();
    std::cout<<"Print clear\n";
    myList.print(); 
    ///PART ONE OF FUNCKY 

    // Test length
    std::cout << "Length: " << myList.length() << std::endl;  

    // Create another linked list
    CLinkedList<int> otherList;
    otherList.append(4);
    otherList.append(5);

    // Test += operator
   myList += otherList;
    myList.print();  

    // Test == operator
    std::cout << "Lists are equal: " << (myList == otherList) << std::endl;  

    // Test -= operator
    CLinkedList<int> *diffList = myList - otherList;
    diffList->print();  
    // Test removeDuplicates
    myList.append(4);
    myList.append(5);
    myList.removeDuplicates();
    
    std::cout<<"Testing remove duplicates\n";
    myList.print();  
    // Test consume
    
    std::cout<<"Testing consume\n";
    myList.consume(otherList);
    myList.print(); 

   // myList.filter(">",4);//segg
   //myList.print(); 
   myList.filter(">",4);//segg
    myList.filter("<",4);
    myList.filter("==",4);
    myList.filter("+",4);
    myList.filter("-",4);
   std::cout<<"Checking slice\n";
   myList.slice(2,4);
    myList.print(); 
}

int main(){
    
    t3();
    std::cout<<"---------------------------------------------------------------"<<std::endl;
    t4();
    std::cout<<"---------------------------------------------------------------"<<std::endl;
    t2();
    std::cout<<"---------------------------------------------------------------"<<std::endl;
     t1();
     std::cout<<"---------------------------------------------------------------"<<std::endl;
tdouble();
     std::cout<<"---------------------------------------------------------------"<<std::endl;
tfloat();
     std::cout<<"---------------------------------------------------------------"<<std::endl;
     tshort();
     std::cout<<"---------------------------------------------------------------"<<std::endl;
     tmine();
     std::cout<<"---------------------------Its over!!!!------------------------"<<std::endl;

    CLinkedList<int> myList;

    // Test prepend, append, and print
    myList.prepend(1);
    myList.prepend(2);
    myList.prepend(3);
    myList.prepend(4);
     myList.prepend(5);

    myList.print();
    std::cout<<myList.length()<<std::endl;
    myList.swap(2,4);
    std::cout<<"Swapping stuff\n";
    myList.print();
    std::cout<<"using []\n";
    std::cout<<myList.operator[](2)<<std::endl;

std::cout<<"---------------------------Its over!!!!------------------------"<<std::endl;

    CLinkedList<float> myList2;

    // Test prepend, append, and print
    myList2.prepend(1);
    myList2.prepend(2);
    myList2.prepend(3);
    myList2.prepend(4);
     myList2.prepend(5);

    myList2.print();
    std::cout<<myList2.length()<<std::endl;
    myList2.swap(2,4);
    std::cout<<"Swapping stuff\n";
    myList2.print();
    std::cout<<"using []\n";
    std::cout<<myList2.operator[](2)<<std::endl;

    std::cout<<"---------------------------Its over!!!!------------------------"<<std::endl;

    CLinkedList<double> myList3;

    // Test prepend, append, and print
    myList3.prepend(1);
    myList3.prepend(2);
    myList3.prepend(3);
    myList3.prepend(4);
     myList3.prepend(5);

    myList3.print();
    std::cout<<myList3.length()<<std::endl;
    myList3.swap(2,4);
    std::cout<<"Swapping stuff\n";
    myList3.print();
    std::cout<<"using []\n";
    std::cout<<myList3.operator[](2)<<std::endl;

    std::cout<<"---------------------------Its over!!!!------------------------"<<std::endl;

    CLinkedList<short> myList4;

    // Test prepend, append, and print
    myList4.prepend(1);
    myList4.prepend(2);
    myList4.prepend(3);
    myList4.prepend(4);
     myList4.prepend(5);

    myList4.print();
    std::cout<<myList4.length()<<std::endl;
    myList4.swap(2,4);
    std::cout<<"Swapping stuff\n";
    myList4.print();
    std::cout<<"using []\n";
    std::cout<<myList4.operator[](2)<<std::endl;
    
    return 0;
}