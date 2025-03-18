#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

template<class T>
List<T>::List()
{
    head=NULL;
}



template<class T>
List<T>::~List()
{
//empty
}
/*
template<class T>
Node<T>* List<T>::insert(T data,int pos)
{
//empty
}

template<class T>
int List<T>::remove(T data)
{
//empty
}

template<class T>
Node<T>* List<T>::operator[](int index)const
{
//empty    
}

template<class T>
Node<T>* List<T>::operator()(T* dataPtr)const
{
//empty    
}

template<class T>
int List<T>::getIndexFromFront(T data)const
{
//empty    
}

template<class T>
int List<T>::getIndexFromRear(T data)const
{
//empty    
}

template<class T>
List<T>* List<T>::sort(bool order)const
{
//empty    
}

template<class T>
Node<T>* List<T>::findSmallest()const
{//empty
    
}

template<class T>
Node<T>* List<T>::findBiggest()const
{
//empty    
}

template<class T>
List<T>* List<T>::clone()const
{
//empty    
}

*/

template<class T>
int List<T>::size()const
{
    if(head==NULL)
    {
        return 0;
    }

    int nodes=0;//to count number of nodes

    //go thorugh list

    Node<T>* nodePtr=head;

    while(nodePtr != NULL)
    {
        nodes++;
        nodePtr=nodePtr->next;
    }

    return nodes;
}

template<class T>
bool List<T>::contains(T data)const
{
     if(head==NULL)
    {
        return false;
    }

    
    //int nodes=0;//to count number of nodes

    //go thorugh list
    bool present= false;

    Node<T>* nodePtr=head;

    while(nodePtr != NULL)
    {
       // nodes++;
        if(nodePtr->getData() == data)
        {
            return true;
        }

        nodePtr=nodePtr->next;
    }

    return false;
}

/*
template <class T>
std::ostream& operator<<(std::ostream& os,const List<T>* node)
{
//empty
}*/




#endif /*LIST_CPP*/