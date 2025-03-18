/*
Output for this main is inside output.txt
Note that output.txt is what my program prints when running this main, thus you should get exactly the same output as the textfile
*/
#include "node.h"

int main() {
    node* list1 = new node(2);//creates the head,cant be NULL
    list1->insert(4);
    list1->insert(6);
    list1->insert(8);
    list1->insert(10);

    node* list2 = new node(5);
    list2->insert(1);
    list2->insert(3);
    list2->insert(7);
    list2->insert(9);
     std::cout<<"Length of list 1:"<<list1->length()<<std::endl;
    std::cout<<"Length of list 2:"<<list2->length()<<std::endl;
    std::cout<<"The tail for list 2 is here:"<<list2->tail()<<std::endl;
    std::cout<<"The tail for list 1 is here:"<<list1->tail()<<std::endl;
    std::cout<<"The head for list 2 is here:"<<list2->head()<<std::endl;
    std::cout<<"The head for list 1 is here:"<<list1->head()<<std::endl;
    std::cout<<"-----------------------------------------------------------------"<<std::endl;
   
    list1->print();
    list2->print();

    list1->insert(list2);
    list1->print();
    list2->print();
     std::cout<<"Length of list 1:"<<list1->length()<<std::endl;
    std::cout<<"Length of list 2:"<<list2->length()<<std::endl;
    std::cout<<"The tail for list 2 is here:"<<list2->tail()<<std::endl;
    std::cout<<"The tail for list 1 is here:"<<list1->tail()<<std::endl;
    std::cout<<"The head for list 2 is here:"<<list2->head()<<std::endl;
    std::cout<<"The head for list 1 is here:"<<list1->head()<<std::endl;
   
    std::cout<<"-------------------------------------------------------------------------\n";
    list2->remove(3);
    std::cout<<"After removing 3 from list 2:";
    list2->print();
    std::cout<<"This is list 1:";
    list1->print();

    std::cout<<"Length of list 1:"<<list1->length()<<std::endl;
    std::cout<<"Length of list 2:"<<list2->length()<<std::endl;
    std::cout<<"Does list one contain 2:"<<list1->contains(2)<<std::endl;
    std::cout<<"Does list one contain 11:"<<list1->contains(11)<<std::endl;
    std::cout<<"The tail for list 2 is here:"<<list2->tail()<<std::endl;
    std::cout<<"The tail for list 1 is here:"<<list1->tail()<<std::endl;
    std::cout<<"The head for list 2 is here:"<<list2->head()<<std::endl;
    std::cout<<"The head for list 1 is here:"<<list1->head()<<std::endl;

    list1->destroyList();
    //list2->destroyList();
    return 0;
}